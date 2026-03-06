#include "calculator.h"
#include <cmath>
#include <locale.h>
#include <stdexcept>
#include <ncurses.h>
#include <string>
#include <vector>

int main() {
  setlocale(LC_ALL, ""); // To support unicode characters like √
  initscr();             // Initialize ncurses
  noecho();              // Don't echo input
  cbreak();              // Line buffering disabled
  keypad(stdscr, TRUE);  // Enable arrow keys
  curs_set(0);           // Hide cursor initially

  std::vector<std::string> choices = {
      "Square Root", "Factorial (unimplemented)",
      "Natural Logarithm (unimplemented)", "Power (unimplemented)", "Exit"};
  int num_choices = choices.size();
  int highlight = 0;
  int choice = -1;
  int c;

  double number;

  while (true) {
    clear();
    printw("\n=== Interactive Calculator ===\n");
    for (int i = 0; i < num_choices; i++) {
      if (i == highlight) {
        attron(A_REVERSE);
      }
      printw("%d. %s\n", i + 1 == num_choices ? 0 : i + 1, choices[i].c_str());
      if (i == highlight) {
        attroff(A_REVERSE);
      }
    }

    c = getch();
    switch (c) {
    case KEY_UP:
      highlight--;
      if (highlight < 0)
        highlight = num_choices - 1;
      break;
    case KEY_DOWN:
      highlight++;
      if (highlight >= num_choices)
        highlight = 0;
      break;
    case 10: // Enter key
      choice = highlight;
      break;
    default:
      break;
    }

    if (choice != -1) {
      if (choice == 4) { // Exit
        break;
      } else if (choice == 0) { // Square Root
        clear();
        printw("Enter a number: ");
        refresh();

        echo();
        curs_set(1);

        int scan_res = scanw("%lf", &number);

        noecho();
        curs_set(0);

        if (scan_res != 1) {
          printw("Invalid input.\n");
        } else {
          try {
            printw("Result:  %g\n", calculator::square_root(number));
          } catch (const std::invalid_argument& e) {
            printw("%s\n", e.what());
          }
        }
        printw("Press any key to continue...");
        refresh();
        getch();
        choice = -1; // Reset choice to go back to menu
      } else if (choice >= 1 && choice <= 3) { // Unimplemented functions
        clear();
        printw("Error: The '%s' function is currently unimplemented.\n",
               choices[choice].c_str());
        printw("Press any key to continue...");
        refresh();
        getch();
        choice = -1; // Reset choice to go back to menu
      }
    }
  }

  endwin();
  return 0;
}