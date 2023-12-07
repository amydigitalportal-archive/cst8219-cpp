#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include "Test.h"

#include <iomanip>
#include <iostream>

using namespace std;

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 700

#define STR_BTN_UNIFORM "Uniform"
#define STR_BTN_NORMAL "Normal"
#define STR_BTN_QUIT "Quit"

#define LABEL_PROMPT "label_prompt"
#define TB_INPUT "tb_input"
#define BTN_UNIFORM "btn_uniform"
#define BTN_NORMAL "btn_normal"
#define TB_OUTPUT "tb_output"
#define BTN_QUIT "btn_quit"

/* -- Static & Helpers */

void LogToConsole(nana::textbox* tb, std::string text)
{
    tb->append(text + "\n", false);
}

int ParseInt(std::string s)
{
    return stoi(s);
}

template <typename T>
string RunTests(Test<T>* pTest)
{
    /* Display Test Header */
    std::string output = std::format("[   {}   ]", pTest->GetName()) + "\n";
    output += std::format("- # of samples: {}\n", pTest->GetNumSamples());
    auto min = pTest->GetMin(), max = pTest->GetMax();
    output += std::format("- Min: {} | Max: {}\n", min, max);
    auto range = max - min;
    auto bucketSize = range / NUM_BUCKETS;
    output += std::format("(Range of values: {} | Size of each bucket: {} )\n", range, bucketSize);
    output += string("-----------------\n");

    /* Display Histogram */
    auto hist = pTest->GetHistogram();
    int b = 1;
    for (T count : hist) {
        output += std::format("[{}] : ", b++);
        for (int n = 0; n < count; n++)
            output += "*";
        output += "\n";
    }

    return output;
}


/*-- MAIN */

int main()
{
    using namespace nana;

    const nana::size WINDOW_SIZE{ WINDOW_WIDTH, WINDOW_HEIGHT };

    // Define a form (window).
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
    tb_output->editable(false); // Set Read-only.
    tb_output->append("\n", false); // Initial update

    /*-- Button: Quit */
    button btn_quit{ fm, STR_BTN_QUIT };

    // Layout management
    //fm.div("vert <><<><weight=80% text><>><><weight=24<><button><>><>");
    fm.div("vert margin=[0,10] \
        <weight=5% margin=[10,0] label_prompt>\
        <weight=5% tb_input> \
        <weight=7% margin=[10,0] \
            <btn_uniform> \
            <btn_normal> \
        > \
        <tb_output> \
        <weight=7% margin=[10,0] btn_quit>");

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
            UniformTest<int>* test = new UniformTest<int>(ParseInt(tb_input.text()));
            std::string output = RunTests(test);
            LogToConsole(tb_output, output);
        }
    });

    btn_normal.events().click([&tb_input, &tb_output] {
        cout << STR_BTN_NORMAL << endl;

        if (tb_input.text().empty() == false)
        {
            NormalTest<double>* test = new NormalTest<double>(ParseInt(tb_input.text()));
            std::string output = RunTests(test);
            LogToConsole(tb_output, output);
        }
    });

    btn_quit.events().click(API::exit); // Ref: https://stackoverflow.com/a/33582771


    fm.collocate();

    //Show the form
    fm.show();

    //Start to event loop process, it blocks until the form is closed.
    exec();
}