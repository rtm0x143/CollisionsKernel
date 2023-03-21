#pragma once
#include <stdlib.h>
#include <sal.h>

extern unsigned _Instance_IdCounter;

#define INSTANCE_NEXT_ID ++_Instance_IdCounter;

typedef void* ExternalHandle; // An pointer to object recived from API consumer

struct _Component {
	ExternalHandle handle;
};

struct _ComponentNode {
	struct _Component* value;
	struct _ComponentProvider* root;
	_Maybenull_ struct _ComponentNode* next;
};

struct _ComponentProvider {
	_Maybenull_ struct _ComponentNode* componentList;
};

typedef struct _Instance {
	struct _ComponentProvider providerRoot;
	unsigned id;
	ExternalHandle handle;
}*Instance;
