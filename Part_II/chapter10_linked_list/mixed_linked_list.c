#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159

enum {
	RECT,
	TRI,
	CIR
};

struct mixlist {
	int type;
	void* data;
	struct mixlist* next;
};
typedef struct mixlist MixList;

struct rectangle {
	float b;
	float h;
};
typedef struct rectangle Rectangle;

struct triangle {
	float b;
	float h;
};
typedef struct triangle Triangle;

struct circle {
	float r;
};
typedef struct circle Circle;

/* create function: returns an empty list */
MixList* mixlst_create (void)
{
    return NULL;
}

/* creates a node with a rectangle */
MixList* create_rect (float b, float h)
{
	Rectangle* r;
	MixList* p;
	
	r = (Rectangle*) malloc(sizeof(Rectangle));
	r->b = b;
	r->h = h;
	
	p = (MixList*) malloc(sizeof(MixList));
	p->type = RECT;
	p->data = r;
	p->next = NULL;
	return p;
}

/* creates a node with a rectangle */
MixList* create_tri (float b, float h)
{
	Triangle* t;
	MixList* p;
	
	t = (Triangle*) malloc(sizeof(Triangle));
	t->b = b;
	t->h = h;
	
	p = (MixList*) malloc(sizeof(MixList));
	p->type = TRI;
	p->data = t;
	p->next = NULL;
	return p;
}

/* creates a node with a circle */
MixList* create_cir (float r)
{
	Circle* c;
	MixList* p;
	
	c = (Circle*) malloc(sizeof(Circle));
	c->r = r;
	
	p = (MixList*) malloc(sizeof(MixList));
	p->type = CIR;
	p->data = c;
	p->next = NULL;
	return p;
}

/* auxiliar function: calculates the area of the node data */
static float area (MixList* p)
{
	float a;
	
	switch(p->type) {
		case RECT:
		{
			Rectangle *r = (Rectangle*) p->data;
			a = r->b * r->h;
		}
		break;
		case TRI:
		{
			Triangle *t = (Triangle*) p->data;
			a = (t->b * t->h) / 2;
		}
		break;
		case CIR:
		{
			Circle *c = (Circle*) p->data;
			a = PI * c->r * c->r;
		}
		break;
	}
	return a;
}

/* calculates the greatest area */
float max_area (MixList* l)
{
	float amax = 0.0;
	MixList* p;
	for(p=l; p!=NULL; p=p->next) {
		float a = area(p);
		if(a > amax)
			amax = a;
	}
	return amax;
}
