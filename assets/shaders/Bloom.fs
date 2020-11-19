#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;

// Output fragment color
out vec4 finalColor;

// Bloom Parameters
const vec2 size = vec2(1080, 720);   // render size
const float samples = 15.0;          // pixels per axis; higher = bigger glow, worse performance
const float quality = 1; 	        // lower = smaller glow, better quality


#define PI 3.1415926538

vec4 scanLineIntensity(float uv, float resolution, float opacity)
    {
        float intensity = sin(uv * resolution * PI * 2.0);
        intensity = ((0.5 * intensity) + 0.5) * 0.9 + 0.1;
        return vec4(vec3(pow(intensity, opacity)), 1.0);
    }

void main()
{
    vec4 result;
    // CURVED UV-----------------------------------------
    vec2 uv   = fragTexCoord * 2.0 - 1.0;
    vec2 offset = abs(uv.yx) / vec2(3, 3);
    uv = uv + uv * offset * offset;
    uv = uv * 0.5 + 0.5;
    //---------------------------------------------------------

    //BLOOM -----------------------------------------------
    vec4 sum = vec4(0);
    vec2 sizeFactor = vec2(1)/size*quality;
    vec4 source = texture(texture0, uv);
    const int range = 7; //  (samples - 1)/2;

    for (int x = -range; x <= range; x++)
    {
        for (int y = -range; y <= range; y++)
        {
            sum += texture(texture0, uv + vec2(x, y)*sizeFactor);
        }
    }
  
    result = ((sum/(samples*samples)) + source)*colDiffuse;
    //--------------------------------------------------------

    //RGB STRIDES ---------------------------------------
   float x = uv.x *1080 /4;
   float mod = mod(x, 3);
   float step1 = step(2, mod);
   float step2 = step(1, mod);

   float r = (1-step2 )- step1;;
   float g = 1-(1-step2 + step1);
   float b = step2-g;
   vec4 rgbStripes = vec4(r,g,b,1);
   result += rgbStripes * 0.03;
   // ---------------------------------------------------------

    // STRIDES --------------------------------------------
   result += abs(fract(uv.y *100))*.15;
    //-------------------------------------------------------


    // VIGNETTE-------------------------------------------
    float intensity = uv.x * uv.y * (1.0 - uv.x) * (1.0 - uv.y);
     vec4 vignette =  vec4(vec3(clamp(pow((1080 / 2) * intensity, 1), 0.0, 1.0)), 1.0);
     //--------------------------------------------------------


    finalColor = result* vignette;

    finalColor *= scanLineIntensity(uv.y, 1080/4, 0.4);
    finalColor *= scanLineIntensity(uv.x, 720/4, 0.4);
}
