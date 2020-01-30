struct point 
{
	float x; 
	float y; 
	float z; 
};

struct face
{
	int vtx[3];
};

struct model
{
	point obj_points[10];
	face obj_faces[4];
	int vertices;
	int faces;
};


//-------- Functions --------------------------------

void Render();
// The function responsible for drawing everything in the 
// OpenGL context associated to a window. 

void Resize(int w, int h);
// Handle the window size changes and define the world coordinate 
// system and projection type

void Setup();
// Set up the OpenGL state machine and create a light source

void Idle();

void ReadFile(model*);
//Function for reading a model file

void DisplayModel(model);
// Function for displaying a model

void Keyboard(unsigned char key,int x,int y);
// Function for handling keyboard events,
//which belong in the ASCII table.
//ex. Characters, Numbers, Symbols, Escape, Space bar, e.t.c.

void Keyboard2(int key,int x,int y);
// Function for handling keyboard special events,
// like non-ASCII keys. 
// ex. Cursor Keys, Function Keys, Page Up, Page Down, e.t.c.

void Mouse(int button,int state,int x,int y); 
// Function for handling mouse events

void MenuSelect(int choice);

