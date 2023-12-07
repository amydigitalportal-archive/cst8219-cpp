#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>
//#include "TestRunner.h"
#include "Test.h"

#include <iomanip>
#include <iostream>

using namespace std;

#define WINDOW_WIDTH 350
#define WINDOW_HEIGHT 600

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

void RunUniformTests(int numSamples, nana::textbox* console)
{
	UniformTest uni(numSamples);

    /* Display Test Header */
	std::string output = string("[   Uniform distribution   ]") + "\n";
    output += std::format("- # of samples: {}\n", numSamples);
	auto min = uni.GetMin(), max = uni.GetMax();
	output += std::format("- Min: {} | Max: {}\n", min, max);
	auto range = max - min;
	auto bucketSize = range / NUM_BUCKETS;
	output += std::format("(Range of values: {} | Size of each bucket: {} )\n", range, bucketSize);
	output += string("-----------------\n");

    /* Display Histogram */
	std::vector<int> hist = uni.GetHistogram();
	int b = 1;
	for (int count : hist) {
		output += std::format("[{}] : ", b++) ;
        for (int n = 0; n < count; n++)
            output += "*";
        output += "\n";
	}
	LogToConsole(console, output);
}

void RunNormalTests(int numSamples, nana::textbox* console)
{

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
        <weight=7% margin=[10,0] label_prompt>\
        <weight=5% tb_input> \
        <weight=10% margin=[10,0] \
            <btn_uniform> \
            <btn_normal> \
        > \
        <tb_output> \
        <weight=10% margin=[10,0] btn_quit>");

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
            //LogToConsole(tb_output, tb_input.text());
            RunUniformTests(ParseInt(tb_input.text()), tb_output);
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
}