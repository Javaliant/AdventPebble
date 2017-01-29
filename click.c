/* Author: Luigi Vincent
* Pebble SDK standard click event template
*/

#include <pebble.h>

static Window *window;
static TextLayer *text_layer;

void handle_up_click() {
	text_layer_set_text(text_layer, "I");
}

void handle_select_click() {
	text_layer_set_text(text_layer, "Love");
}

void handle_down_click() {
	text_layer_set_text(text_layer, "Programming");
}

void configure_click_handlers() {
	window_single_click_subscribe(BUTTON_ID_UP, handle_up_click);
	window_single_click_subscribe(BUTTON_ID_SELECT, handle_select_click);
	window_single_click_subscribe(BUTTON_ID_DOWN, handle_down_click);
}



static void load(Window *window) {
	// Set window properties
	window_set_background_color(window, GColorLiberty);
	window_set_click_config_provider(window, configure_click_handlers);
	// Get information about the window
	Layer *window_layer = window_get_root_layer(window);
	GRect bounds = layer_get_bounds(window_layer);

	// Create layer with specific bounds
	text_layer = text_layer_create(GRect(0, PBL_IF_ROUND_ELSE(58, 52), bounds.size.w, 50));
	// Add centered, colored text
	text_layer_set_text(text_layer, "I am Luigi");
	text_layer_set_background_color(text_layer, GColorLiberty);
	text_layer_set_text_color(text_layer, GColorRajah);
	text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);

	// Add to parent layer
	layer_add_child(window_layer, text_layer_get_layer(text_layer));
}

static void unload(Window *window) {
	text_layer_destroy(text_layer);
}

static void init(void) {
	window = window_create();
	window_set_window_handlers(window, (WindowHandlers) {
		.load = load,
		.unload = unload
	});
	window_stack_push(window, true);
}

static void deinit(void) {
	window_destroy(window);
}

int main(void) {
	init();
	app_event_loop();
	deinit();
}
