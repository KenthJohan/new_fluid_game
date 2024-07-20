#pragma once
#include <flecs.h>

typedef struct {
	void * data;
	uint32_t size;
	uint32_t width;
	uint32_t height;
	uint8_t depth;
} image_t;


typedef struct {
	ecs_world_t *world;
	uint32_t image_id;
	uint32_t image_id2;
	image_t image;
	bool show_window_extra2;
} app_t;