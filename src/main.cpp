#include <LibGUI/Application.h>
#include <LibGUI/Window.h>
#include <LibGUI/ImageWidget.h>
#include <LibGUI/Button.h>
#include <LibGUI/MessageBox.h>

#include "../ExampleWindowGML.h"

// TODO: Get `serenity_main` working instead of classic UNIX `main`

int main(int argc, char* argv[]) {
    auto app = MUST(GUI::Application::try_create(argc, argv));
    auto window = MUST(GUI::Window::try_create());
    auto widget = MUST(window->try_set_main_widget<GUI::Widget>());

    widget->load_from_gml(example_window_gml);

    auto& icon = *widget->find_descendant_of_type_named<GUI::ImageWidget>("icon");
    auto& demo_button = *widget->find_descendant_of_type_named<GUI::Button>("demo_button");
    auto& close_button = *widget->find_descendant_of_type_named<GUI::Button>("close_button");

    icon.load_from_file("/res/icons/32x32/ladyball.png");

    demo_button.on_click = [&](auto) {
        GUI::MessageBox::show(
            window,
            "This is my little application!",
            "Oh hi there! :^)",
            GUI::MessageBox::Type::Information,
            GUI::MessageBox::InputType::OK
        );
    };

    close_button.on_click = [&](auto) {
        app->quit();
    };

    window->set_title("Example");
    window->resize(300, 150);
    window->show();

    return app->exec();
}
