#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>

#include "RNG.h"

#include <iostream>

using namespace std;

#define STR_BTN_UNIFORM "Uniform"
#define STR_BTN_NORMAL "Normal"
#define LABEL_PROMPT "label_prompt"
#define INPUT_TB "input_tb"
#define BTN_UNIFORM "btn_uniform"
#define BTN_NORMAL "btn_normal"

//#define LAUNCH_GUI

int main()
{
#ifdef LAUNCH_GUI
    using namespace nana;

    //Define a form.
    form fm;

    /*-- Label: Prompt n-samples input */
    label label_prompt{ fm, "<bold blue size=16>Enter the number of samples to generate:</>" };
    label_prompt.format(true);

    /*-- TextBox: n-samples */
    textbox tb{ fm, "Number of samples" };

    /*-- Button: Uniform */
    button btn_uniform{ fm, STR_BTN_UNIFORM };
    btn_uniform.events().click([&fm] {
        cout << STR_BTN_UNIFORM << endl;
        });

    /*-- Button: Normal */
    button btn_normal{ fm, STR_BTN_NORMAL };
    btn_normal.events().click([] {
        cout << STR_BTN_NORMAL << endl;
        });

    //Layout management
    //fm.div("vert <><<><weight=80% text><>><><weight=24<><button><>><>");
    fm.div("vert <label_prompt><input_tb>< <btn_uniform> <btn_normal> >");
    fm[LABEL_PROMPT] << label_prompt;
    fm[INPUT_TB] << tb;
    fm[BTN_UNIFORM] << btn_uniform;
    fm[BTN_NORMAL] << btn_normal;

    fm.collocate();

    //Show the form
    fm.show();

    //Start to event loop process, it blocks until the form is closed.
    exec();
#else


    return 0;

#endif
}