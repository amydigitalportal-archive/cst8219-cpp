#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>
//#include "TestRunner.h"
#include "Test.h"


#include <iostream>

using namespace std;

#define STR_BTN_UNIFORM "Uniform"
#define STR_BTN_NORMAL "Normal"
#define STR_BTN_QUIT "Quit"

#define LABEL_PROMPT "label_prompt"
#define TB_INPUT "tb_input"
#define BTN_UNIFORM "btn_uniform"
#define BTN_NORMAL "btn_normal"
#define TB_OUTPUT "tb_output"
#define BTN_QUIT "btn_quit"

#define LAUNCH_GUI

void LogToConsole(nana::textbox* tb, std::string text)
{
    tb->append(text + "\n", false);
}

int ParseInt(std::string s)
{
    return stoi(s);
}

void RunUniformTests(int numSamples)
{

}

void RunNormalTests(int numSamples)
{

}


/*-- MAIN */

int main()
{
#ifdef LAUNCH_GUI
    using namespace nana;

    const nana::size WINDOW_SIZE{ 300, 400 };

    //Define a form.
    form fm;
    fm.size(WINDOW_SIZE);
    // Prevent window from resizing
    // Ref: http://www.nanapro.org/en-us/forum/index.php?u=/topic/1069/how-to-prevent-resizing-a-form
    API::track_window_size(fm, WINDOW_SIZE, false);
    API::track_window_size(fm, WINDOW_SIZE, true);

    /*-- Label: Prompt n-samples input */
    label label_prompt{ fm, "Enter the number of samples to generate:" };
    label_prompt.format(true);
    label_prompt.text_align(nana::align::center, nana::align_v::center);

    /*-- TextBox: n-samples */
    textbox tb_input{ fm, "" };
    tb_input.tip_string("Number of samples");

    /*-- Button: Uniform */
    button btn_uniform{ fm, STR_BTN_UNIFORM };

    /*-- Button: Normal */
    button btn_normal{ fm, STR_BTN_NORMAL };
    
    /*-- TextBox: Output */
    textbox* tb_output = new textbox{ fm, "" };
    tb_output->editable(false);

    /*-- Button: Quit */
    button btn_quit{ fm, STR_BTN_QUIT };

    //Layout management
    //fm.div("vert <><<><weight=80% text><>><><weight=24<><button><>><>");
    fm.div("vert margin=[0,10] <weight=10% margin=[10,0] label_prompt><weight=10% tb_input><weight=15% margin=[10,0] <btn_uniform> <btn_normal> > <tb_output> <weight=10% margin=[10,0] btn_quit>");
    fm[LABEL_PROMPT] << label_prompt;
    fm[TB_INPUT] << tb_input;
    fm[BTN_UNIFORM] << btn_uniform;
    fm[BTN_NORMAL] << btn_normal;
    fm[TB_OUTPUT] << *tb_output;
    fm[BTN_QUIT] << btn_quit;

    // -- Button Events

    btn_uniform.events().click([&tb_input, &tb_output] {
        cout << STR_BTN_UNIFORM << endl;

        // If Input field is NOT empty...
        if (tb_input.text().empty() == false)
        {
            LogToConsole(tb_output, tb_input.text());
        }
    });

    btn_normal.events().click([&tb_input, &tb_output] {
        cout << STR_BTN_NORMAL << endl;

    });

    btn_quit.events().click(API::exit); // Ref: https://stackoverflow.com/a/33582771


    fm.collocate();

    //Show the form
    fm.show();

    //Start to event loop process, it blocks until the form is closed.
    exec();
#else
    //TestRunner* runner = new TestRunner();
    //runner->SetNumSamples(500);

    //vector<int> myNums = runner->RunUniformTests();
    //vector<int> myNums = runner->RunNormalTests();
    
    //for (int n : myNums)
    //    cout << n << ' ';
    //cout << endl;

    UniformTest u(1000);

    return 0;
#endif
}