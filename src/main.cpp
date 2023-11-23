#include "global_includes.hpp"
#include "cell.hpp"
#include "string.h"
size_t n_cells = 64, n_loops = 32; 
int ElemAutomataRuleID = 30;
std::string paradigm = "pon";
void run_imperative_elementary_automata();

int main(int argc, char **argv)
{

  if (argc >= 2)
    n_cells = atoi(argv[1]);
  if (argc >= 3)
    n_loops = atoi(argv[2]);
  if (argc >= 4)
    ElemAutomataRuleID = atoi(argv[3]); //possible rules: 30 90 110 184 250 254
  if (argc >= 5)
    paradigm = paradigm.assign(argv[4]);


  if(paradigm.compare("nop") != 0) {
    run_imperative_elementary_automata(); 

    return 0;
  }
  
  std::cout << "Notification Oriented Paradigm" << std::endl;
  std::cout << "Elementary Cellular Automata: Rule " << ElemAutomataRuleID << std::endl;
  std::cout << "Creating " << n_cells << " cells" << std::endl;

  std::vector<std::shared_ptr<Cell>> cells;
  auto creation_start = NOW();

  for (size_t i = 0; i < n_cells; i++) {
    cells.push_back(std::make_shared<Cell>(ElemAutomataRuleID));
    cells[i]->setID((i));
  }

  auto creation_end = NOW();
  auto creation_time = TO_MS(creation_end - creation_start);

  std::cout << "Cells created in " << creation_time << " ms" << std::endl;

  std::cout << "Initializing cells " << std::endl;

  auto activation_start = NOW();
  cells[n_cells/2]->atState->SetValue(true); //assign the "true" state to the middle cell
  cells[n_cells/2]->atTransitionState->SetValue(true);
  int sumChanges_t2 = 0;
  int sumChanges_t1 = 0;
  int sumChanges_t;
  for (size_t it = 0; it < n_loops; it++) {
    sumChanges_t = 0;

    for (size_t i = 1; i < n_cells-1; i++) {
      std::cout << char( cells[i]->atState->GetValue() & 1 ? 'O' : '.');
      cells[i]->unready();
      cells[i]->setNeighbors_1D(cells[(i-1)]->atTransitionState->GetValue(), cells[(i+1)]->atTransitionState->GetValue()); //set left and right neighbors
    }
         
    for (size_t i = 1; i < n_cells-1; i++) {
      cells[i]->ready();
      sumChanges_t += cells[i]->atRuleExecuted->GetValue();
      cells[i]->atRuleExecuted->SetValue(0);
    }
    std::cout << " Changes this loop: " << sumChanges_t2;
    std::cout << std::endl;

    sumChanges_t2 = sumChanges_t1;
    sumChanges_t1 = sumChanges_t;
  }
  auto activation_end = NOW();
  auto activation_time = TO_MS(activation_end - activation_start);

  std::cout << "Number of cells:  " << n_cells << std::endl;
  std::cout << "Number of loops:    " << n_loops << std::endl;
  std::cout << "Total time: " << activation_time << " ms" << std::endl;
  std::cout << "Average loop time: " << activation_time / n_loops << " ms" << std::endl;
  
  std::cout << "Changes by Cell id: " << std::endl;
 
  int avg_changes = 0;
  for (size_t i = 0; i < n_cells; i++) {
     std::cout << i << ": " << cells[i]->atChanges->GetValue() << std::endl;
     avg_changes += cells[i]->atChanges->GetValue();
  }
  std::cout << "State transition count: " << avg_changes <<std::endl;
  std::cout << "Average state transitions: " << avg_changes/n_cells <<std::endl;
  return 0;
}

void run_imperative_elementary_automata() {
  std::cout << "Imperative Paradigm" << std::endl;
  std::cout << "Elementary Cellular Automata: Rule " << ElemAutomataRuleID << std::endl;
  auto activation_start = NOW();

  uint64_t state = 1u << 31;
  for (int i = 0; i < n_loops; ++i) {
    for (int j = n_cells; j--;) {
      std::cout << char(state >> j & 1 ? 'O' : '.');
    }
    std::cout << '\n';
    switch (ElemAutomataRuleID) {
      case 30:  //executes rule 30 
        state = (state >> 1) ^ (state | state << 1);
        break;
      case 90:  //executes rule 90 (XOR)
        state = (state >> 1) ^ (state << 1);
        break;
      case 110: //executes rule 110
        state = ~(state >> 1) & (state << 1) | ((state) ^ (state << 1));
        //atState->SetValue(!atStateLeft->GetValue() && atStateRight->GetValue() || (atState->GetValue() ^ atStateRight->GetValue()));
        break;

      case 184:
       // state = (left or left and center or center and right)
        state = (state >> 1 | state >> 1 & state | state & state << 1);
        break;
      
      case 250: //executes rule 250
        state = (state >> 1) | (state << 1);
        break;

      case 254: //executes rule 254
        state = (state >> 1) | (state << 1) | (state);
        break;

      default:
        break;    
      }
  }
  auto activation_end = NOW();
  auto activation_time = TO_MS(activation_end - activation_start);

  std::cout << "Number of cells:  " << n_cells << std::endl;
  std::cout << "Number of loops:    " << n_loops << std::endl;
  std::cout << "Total time: " << activation_time << " ms" << std::endl;
  std::cout << "Average loop time: " << activation_time / n_loops << " ms" << std::endl;
}