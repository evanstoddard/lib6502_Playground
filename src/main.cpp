#include <gtkmm.h>
#include <iostream>
class MyWindow : public Gtk::Window
{
public:
  MyWindow();
};

MyWindow::MyWindow()
{
  set_title("Basic application");
  set_default_size(200, 200);
}

int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create("");
  MyWindow window;
  return app->run(window, argc, argv);
  return 0;
}