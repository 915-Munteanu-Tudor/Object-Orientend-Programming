#include "app.h"
#include "Qt/QtApp.h"
#include "repoDog.h"
//here I run the app
int main(int argc, char **argv)
{
    Console c;
    RepoDog d;
    Service s(d);
    //c.run_menu_cmd();
    return QtApp(argc, argv, s).loop();

}