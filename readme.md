# MineStorm

### Controls :

**PLAYER ONE :** 
1. “D“ & “Q“ : change the ship rotation (Rotate Player)
1. “Z“ : makes the Player accelerates (Toward the front of the ship)
1. “S” : Shoot a bullet

**PLAYER TWO :**
1. “J“ et “L“ : change the ship rotation (Rotate Player)
1. “I“ :  makes the Player accelerates (Toward the front of the ship)
1. “K” : Shoot a bullet

Additional controls in-game to display shaders and debug. (F1, F2)


### Entity System
* An EntityManager manages all the entity in the game (**EntityManager.h**)
* Instantiates prefabs at the beggining of the game, is able to destroy them safely
* Is accessible to all the classes and makes easy instantiation & destroying entities

### Collision System
* Three layers:
	* Grid system to split the physics system in cells for optimization (**Physics2D.h**)
	* AABB Check (**Entity.h**)
	* SAT Algorithm (**Physics2D.h**)
* A tool that uses a texture to generate polygons & vertices (**PolygonHelper.cpp**)
	
### Shaders
* A Post-Process shader to simulate retro monitor (**Bloom.fs**)
	* Bloom
	* Bumped UV
	* RGB Strides
	* Old pixel look

### Player
* Movement in accordance with the law of inertia (**Player.cpp -> GetInput() **)
* Trail Renderer (**Player.cpp -> RenderTrail()**)

### Scene Management
* Master class that manages the scene that makes the scene transition easy. (**Master.cpp -> ChangeScene)
* Singleton Pattern


### Helpers & Maths
* Helper class for **Vector2** for basic Vector2 operations
* Helper class for **Sprite** to generate SpriteRect & SpriteOrigins easily
* All maths functions are stored in **Physics2D.cpp** & **Vector2Helper.cpp**

