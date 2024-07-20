#include "test.h"

#define CIMGUI_DEFINE_ENUMS_AND_STRUCTS
#include <cimgui.h>
#include <sokol_app.h>
#include <sokol_gfx.h>
#include <sokol_imgui.h>

/*
#define X 0xFF0000FF
#define o 0xFFCCCCCC
static const uint32_t disabled_texture_pixels[8][8] = {
{X, o, o, o, o, o, o, X},
{o, X, o, o, o, o, X, o},
{o, o, X, o, o, X, o, o},
{o, o, o, X, X, o, o, o},
{o, o, o, X, X, o, o, o},
{o, o, X, o, o, X, o, o},
{o, X, o, o, o, o, X, o},
{X, o, o, o, o, o, o, X}};
#undef X
#undef o
*/



static void modify_image(image_t *image)
{
	uint8_t * color = image->data;
	for (uint32_t x = 0; x < image->width; ++x) {
		for (uint32_t y = 0; y < image->height; ++y) {
			color[0] = x*y;
			color[1] = x^y;
			color[2] = x+y;
			color[3] = 0xFF;
			color += image->depth;
		}
	}
}

void app_gui_window_extra2(app_t *app)
{
	igSetNextWindowPos((ImVec2){100, 100}, ImGuiCond_Once, (ImVec2){0, 0});
	igSetNextWindowSize((ImVec2){400, 300}, ImGuiCond_Once);
	ImGuiWindowFlags_ flags = 0;
	igBegin("Extra2", &app->show_window_extra2, flags);
	if (igSmallButton("Button")) {
		modify_image(&app->image);
		sg_update_image((sg_image){app->image_id2},
		&(sg_image_data){
		.subimage[0][0].ptr = app->image.data,
		.subimage[0][0].size = app->image.size});
	}

	ImTextureID tex_id = simgui_imtextureid((simgui_image_t){app->image_id});
	igImage(tex_id, (ImVec2){500, 500}, (ImVec2){0, 0}, (ImVec2){1, 1}, (ImVec4){1, 1, 1, 1}, (ImVec4){0, 0, 0, 0});

	igEnd();
}