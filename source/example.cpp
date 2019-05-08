#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "circle.hpp"
#include "rectangle.hpp"
#include "color.hpp"


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};


  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    Vec2 v_1 = {400.0f, 400.0f};  //  drawTest for  Rectangles and Circles
    Vec2 v_2 = {500.0f, 500.0f};
    Color c_1 = {1.0f, 0.0f, 1.0f};
    Color c_2 = {0.8f, 0.2f, 0.3f};

    Rectangle r_2{v_1,v_2,c_1};
    r_2.draw(win);

    Circle cir_2{v_1,10.0f,c_2};  // (Param.-center,radius,color)
    cir_2.draw(win);


    Vec2 v_5 = {600.0f, 200.0f};  // draw with custum-line-thickness
    Vec2 v_6 = {300.0f, 300.0f};
    Color c_5 = {0.2f, 0.1f, 0.9f};
    Color c_6 = {0.4f, 0.2f, 0.3f};

             // error: no matching function for call to ‘Rectangle::Rectangle(<brace-enclosed initializer list>)’                      
    Rectangle r_4{v_5,v_1,c_5,20.0f};   //zusätzlicher wert für thickness am ende wird nicht richtig erkannt
    r_4.draw(win);

    Circle cir_3{v_5,20.0f,c_6,50.0f};  // (Param.-center,radius,color)
    cir_3.draw(win);



    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto mouse_position = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
    
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);

    win.update();
  }

  return 0;
}
