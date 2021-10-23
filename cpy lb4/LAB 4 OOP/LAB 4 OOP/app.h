#include <memory>
#include "validators.h"
#include "repoDog.h"
#include "adoption.h"

class Console
{
private:
    RepoDog repoDog;
    std::unique_ptr<AdoptionList> adoptionList = nullptr;
    Validator validator;
public:
    static void print_menu_administrator();
    void run_menu_cmd();
    static void menuForItter();
    static void print_menu_user();
    //void read_from_file();
    static void menu_for_data_store();

};
