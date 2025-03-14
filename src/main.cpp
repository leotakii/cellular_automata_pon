#include "global_includes.hpp"
#include "cell.hpp"
#include "string.h"
#include <stdlib.h>
#include <time.h> 
size_t n_cells = 64, n_loops = 32; 
int ElemAutomataRuleID = 30;
std::string opt_paradigm = "pon";
std::string opt_cell_init_mode = "deterministic";
std::string opt_cell_boundary_mode = "zeroed_border";
std::string opt_output_mode = "csv";
bool isDeterministic = true;
bool isBounded       = true;
bool isHumanReadable = false;
int totalTests       = 100;

void run_imperative_bitwise_elementary_automata();
void run_imperative_vector_elementary_automata();

int main(int argc, char **argv)
{

  if (argc >= 2)
    n_cells = atoi(argv[1]);
  if (argc >= 3)
    n_loops = atoi(argv[2]);
  if (argc >= 4)
    ElemAutomataRuleID = atoi(argv[3]); //possible rules: 30 90 110 184 250 254
  if (argc >= 5)
    opt_paradigm = opt_paradigm.assign(argv[4]);
  if (argc >= 6)
    opt_cell_init_mode = opt_cell_init_mode.assign(argv[5]);
  if (argc >= 7)
    opt_cell_boundary_mode = opt_cell_boundary_mode.assign(argv[6]);
  if (argc >= 8)
    opt_output_mode = opt_output_mode.assign(argv[7]);


  if (opt_output_mode.compare("human") == 0) {
    isHumanReadable = true;
  }

  if(opt_cell_boundary_mode.compare("looped_border") == 0) {
    isBounded = false;
  }

  if(opt_cell_init_mode.compare("random") == 0) { //initiates random seed
      srand(time(0));
      isDeterministic = false;
  }

  if(!isHumanReadable) {
    std::cout << "size_in_bytes" <<"," << "creation_time_ms" << "," << "activation_time_ms" << "," << "average_loop_time_ms" << "," << "total_changes" << "," << "average_changes_per_cell" << "," << "average_changes_per_loop" << std::endl;
  }

  if(opt_paradigm.compare("bit") == 0) { //
    run_imperative_bitwise_elementary_automata(); 
    return 0;
  }

  if(opt_paradigm.compare("vec") == 0) { //
    run_imperative_vector_elementary_automata(); 
    return 0;
  }
  if(isHumanReadable == true) {
    std::cout << "Random Seed = " << !bool(rand() % 2) << std::endl;
    std::cout << "Notification Oriented Paradigm" << std::endl;
    std::cout << "Elementary Cellular Automata: Rule " << ElemAutomataRuleID << std::endl;
    std::cout << "Creating " << n_cells << " cells" << std::endl;
  }
  //Default Scheduler Strategy: FIFO
  //NOP::Scheduler::Instance().SetStrategy(NOP::EStrategy::None);
  //NOP::Scheduler::Instance().SetStrategy(NOP::EStrategy::Keeper);

  std::vector<std::shared_ptr<Cell>> cells;

  nop_test_loop:

  auto creation_start = NOW();

  for (size_t i = 0; i < n_cells; i++) {
    cells.push_back(std::make_shared<Cell>(ElemAutomataRuleID));
    cells[i]->setID((i));
  }

  auto creation_end = NOW();
  auto creation_time = TO_MS(creation_end - creation_start);

  int size_in_bytes = sizeof(Cell)*n_cells;
  if(isHumanReadable == true) {
    std::cout << "Individual Cell memory usage: " << sizeof(Cell) << std::endl;
    std::cout << "Total Cell memory usage: " << sizeof(Cell)*n_cells << "B" <<std::endl;
    std::cout << "Cells created in " << creation_time << " ms" << std::endl;
    std::cout << "Initializing cells " << std::endl;
  }
  auto activation_start = NOW();
 
  cells[n_cells/2]->atTransitionState->SetValue(true); //assign the "true" state to the central cell

  if(isDeterministic == false) {
    //initialize states randomly (except for the border cells)
    bool random_state;
    for (size_t i = int(isBounded); i < n_cells - int(isBounded); i++) {
      random_state = bool(rand() % 2);
      cells[i]->atTransitionState->SetValue(random_state); //assign random states to every cell
    }
  }

  int sumChanges_t;
  for (size_t it = 0; it < n_loops; it++) {
    sumChanges_t = 0;

    //updates left and right neighbors (zeroed bounds)
    for (size_t i = int(isBounded); i < n_cells - int(isBounded); i++) {
      cells[i]->unready();
      cells[i]->setNeighbors_1D(cells[(i-1) % n_cells]->atTransitionState->GetValue(), cells[(i+1) % n_cells]->atTransitionState->GetValue()); 
    }
    if(isHumanReadable) {     
      for (size_t i = int(isBounded); i < n_cells - int(isBounded); i++){
        cells[i]->ready();
        
        std::cout << char( cells[i]->atState->GetValue() & 1 ? '*' : '.');
        sumChanges_t += cells[i]->atRuleExecuted->GetValue();
      }
      std::cout << " Changes this loop: " << sumChanges_t;
      std::cout << std::endl;
    }
    else {
      for (size_t i = int(isBounded); i < n_cells - int(isBounded); i++){
        cells[i]->ready();       
        //sumChanges_t += cells[i]->atRuleExecuted->GetValue();
      }
    }
  }
  auto activation_end = NOW();
  auto activation_time = TO_MS(activation_end - activation_start);
  int total_changes = 0;
  
  for (size_t i = 0; i < n_cells; i++) {
     total_changes += cells[i]->atChanges->GetValue();
  }
  if(isHumanReadable) {   
    std::cout << "Changes by Cell id: " << std::endl;
    for (size_t i = 0; i < n_cells; i++) {
     std::cout << i << ": " << cells[i]->atChanges->GetValue() << std::endl;
    }
    std::cout << "Size in Bytes: " << size_in_bytes << " B" << std::endl;
    std::cout << "Creation time: " << creation_time << " ms" << std::endl;
    std::cout << "Number of cells:" << n_cells << std::endl;
    std::cout << "Number of loops: " << n_loops << std::endl;
    std::cout << "Total time: " << activation_time << " ms" << std::endl;
    std::cout << "Average loop time: " << activation_time / n_loops << " ms" << std::endl;
    std::cout << "State transition count: " << total_changes <<std::endl;
    std::cout << "Average state transitions per cell: " << total_changes/n_cells <<std::endl;
    std::cout << "Average state transitions per loop: " << total_changes/n_loops <<std::endl;

    cells.clear();
  }
  else {
    cells.clear();
    
     std::cout << size_in_bytes << "," <<creation_time << "," <<activation_time << "," << activation_time / n_loops << "," << total_changes << "," << total_changes/n_cells << "," << total_changes/n_loops << std::endl;
     totalTests--;
     if (totalTests > 0) 
       goto nop_test_loop;

  }
  
  return 0;
}

void run_imperative_vector_elementary_automata(){
  vec_test_loop:
  auto creation_start = NOW();
  bool *cells_even_step;
  cells_even_step = (bool*) calloc(n_cells, sizeof(bool));
  bool *cells_odd_step;
  cells_odd_step  = (bool*) calloc(n_cells, sizeof(bool));

  int *cells_changes;
  cells_changes   = (int*)  calloc(n_cells, sizeof(int));
  int size_in_bytes = n_cells* sizeof(bool) + n_cells* sizeof(bool) + n_cells* sizeof(int); 
  auto creation_end = NOW();
  auto creation_time = TO_MS(creation_end - creation_start);

  auto activation_start = NOW();

  cells_even_step[n_cells/2] = 1;
  cells_odd_step[n_cells/2]  = 1;
  int sumChanges_t = 0;
  
  bool delta_i;

  if(isDeterministic == false) {
    //initialize states randomly (except for the border cells)
    bool random_state;
    for (size_t i = int(isBounded); i < n_cells - int(isBounded); i++) {
      random_state = !bool(rand() % 2);
      cells_even_step[i] = random_state; //assign the "true" state to the middle cell
      cells_odd_step[i] = random_state;
    }
  }

  for (size_t it = 0; it < n_loops; it++) {
    sumChanges_t = 0;

    for (size_t i = int(isBounded); i < n_cells - int(isBounded); i++){
      if (it % 2 == 0) {
        if (isHumanReadable == true)
          std::cout << char(cells_even_step[i] & 1 ? '*' : '.');
        switch (ElemAutomataRuleID) {
        case 30: //executes rule 30 
          cells_odd_step[i] = (cells_even_step[(i-1)  % n_cells] ^ (cells_even_step[i] || cells_even_step[(i+1)  % n_cells]));
        break;
        case 90: //executes rule 90
          cells_odd_step[i] = (cells_even_step[(i-1)  % n_cells] ^ cells_even_step[(i+1)  % n_cells]);
        case 110: //executes rule 110
          cells_odd_step[i] = (!cells_even_step[(i-1)  % n_cells] && cells_even_step[(i+1)  % n_cells] || (cells_even_step[i] ^ cells_even_step[(i+1)  % n_cells]));
          break;
        case 184: //executes rule 184 p ^(q && (p ^ r))
          cells_odd_step[i] = (cells_even_step[(i-1)  % n_cells] ^ (cells_even_step[i] && (cells_even_step[(i-1) % n_cells] ^ cells_even_step[(i+1) % n_cells])));
        break;
        case 250: //executes rule 250
          cells_odd_step[i] = (cells_even_step[(i-1)  % n_cells]  || cells_even_step[(i+1)  % n_cells]);
        case 254: //executes rule 254
          cells_odd_step[i] = (cells_even_step[(i-1)  % n_cells] || cells_even_step[i] || cells_even_step[(i+1)  % n_cells]);
        default:
        break;

        }
      }
      else { //odd steps
        if (isHumanReadable == true)
          std::cout << char(cells_odd_step[i] & 1 ? '*' : '.');
        switch (ElemAutomataRuleID) {
        case 30: //executes rule 30 
          cells_even_step[i] = (cells_odd_step[(i-1)  % n_cells] ^ (cells_odd_step[i] || cells_odd_step[(i+1)  % n_cells]));
        break;
        case 90: //executes rule 90
          cells_even_step[i] = (cells_odd_step[(i-1)  % n_cells] ^ cells_odd_step[(i+1)  % n_cells]);
        case 110: //executes rule 110
          cells_even_step[i] = (!cells_odd_step[(i-1)  % n_cells] && cells_odd_step[(i+1)  % n_cells] || (cells_odd_step[i] ^ cells_odd_step[(i+1)  % n_cells]));
        break;
        case 184: //executes rule 184 p ^(q && (p ^ r))
          cells_even_step[i] = (cells_odd_step[(i-1)  % n_cells] ^ (cells_odd_step[i] && (cells_odd_step[(i-1) % n_cells] ^ cells_odd_step[(i+1) % n_cells])));
        break;
        case 250: //executes rule 250
          cells_even_step[i] = (cells_odd_step[(i-1)  % n_cells]  || cells_odd_step[(i+1)  % n_cells]);
        case 254: //executes rule 254
          cells_even_step[i] = (cells_odd_step[(i-1)  % n_cells] || cells_odd_step[i] || cells_odd_step[(i+1)  % n_cells]);
        default:
        break;
      }

      }
      delta_i = bool(cells_even_step[i] - cells_odd_step[i]);
      cells_changes[i] += bool(delta_i);
      sumChanges_t += bool(delta_i);
    }
    if (isHumanReadable == true)
      std::cout << " Changes this loop: " << sumChanges_t << std::endl;
  }
  auto activation_end = NOW();
  auto activation_time = TO_MS(activation_end - activation_start);
  if (isHumanReadable == true)
    std::cout << "Changes by Cell id: " << std::endl;
 
  int total_changes = 0;
  
  for (size_t i = 0; i < n_cells; i++) {
     if (isHumanReadable == true)
      std::cout << i << ": " << cells_changes[i] << std::endl;
     total_changes += cells_changes[i];
  }
  free(cells_even_step);
  free(cells_odd_step);
  free(cells_changes);

  if (isHumanReadable == true){
    std::cout << "Size in Bytes: " << size_in_bytes << " B" << std::endl;
    std::cout << "Total time: " << creation_time << " ms" << std::endl;
    std::cout << "Number of cells:" << n_cells << std::endl;
    std::cout << "Number of loops: " << n_loops << std::endl;
    std::cout << "Total time: " << activation_time << " ms" << std::endl;
    std::cout << "Average loop time: " << activation_time / n_loops << " ms" << std::endl;
    std::cout << "State transition count: " << total_changes <<std::endl;
    std::cout << "Average state transitions per cell: " << total_changes/n_cells <<std::endl;
    std::cout << "Average state transitions per loop: " << total_changes/n_loops <<std::endl;

  }

  else {
     std::cout << size_in_bytes << "," <<creation_time << "," <<activation_time << "," << activation_time / n_loops << "," << total_changes << "," << total_changes/n_cells << "," << total_changes/n_loops << std::endl;
    totalTests--;
    if (totalTests > 0) 
      goto vec_test_loop;
  }


  return;
}

void run_imperative_bitwise_elementary_automata() {
  std::cout << "Imperative Paradigm" << std::endl;
  std::cout << "Bitwise Elementary Cellular Automata: Rule " << ElemAutomataRuleID << std::endl;
  auto activation_start = NOW();

  uint64_t state = 1u << 31;
  for (int i = 0; i < n_loops; ++i) {
    for (int j = n_cells; j--;) {
      std::cout << char(state >> j & 1 ? 'O' : '.');
    }
    std::cout << '\n';
    switch (ElemAutomataRuleID) {
      case 30:  //executes rule 30 Class 3 
        state = (state >> 1) ^ (state | state << 1);
        break;
      case 90:  //executes rule 90 (XOR) Class 2 
        state = (state >> 1) ^ (state << 1);
        break;
      case 110: //executes rule 110 Class 4
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