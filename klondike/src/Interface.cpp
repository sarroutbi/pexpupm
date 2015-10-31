#include "Interface.h"

Interface::Interface() {

}

Interface::~Interface() {

}

void Interface::DisplayOptions() {
  std::map<uint8_t, Option*>::const_iterator opit = m_option_list.begin();
  for (; opit != m_option_list.end(); opit++) {
    opit->second->display();
  }
}
