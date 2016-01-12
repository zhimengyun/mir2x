// generated by Fast Light User Interface Designer (fluid) version 1.0302

#include "addmonsterwindow.hpp"

void AddMonsterWindow::cb_Add_i(Fl_Button*, void*) {
  {
    extern SceneServer *g_SceneServer;
    g_SceneServer->AddMonsterType((uint32_t)(m_ValidList->menu()[m_ValidList->value()].user_data()));
    
    Refresh();
};
}
void AddMonsterWindow::cb_Add(Fl_Button* o, void* v) {
  ((AddMonsterWindow*)(o->parent()->user_data()))->cb_Add_i(o,v);
}

void AddMonsterWindow::cb_OK_i(Fl_Button*, void*) {
  {
    m_Window->hide();
};
}
void AddMonsterWindow::cb_OK(Fl_Button* o, void* v) {
  ((AddMonsterWindow*)(o->parent()->user_data()))->cb_OK_i(o,v);
}

void AddMonsterWindow::cb_Refresh_i(Fl_Button*, void*) {
  {
    Refresh();
};
}
void AddMonsterWindow::cb_Refresh(Fl_Button* o, void* v) {
  ((AddMonsterWindow*)(o->parent()->user_data()))->cb_Refresh_i(o,v);
}

AddMonsterWindow::AddMonsterWindow() {
  { m_Window = new Fl_Double_Window(300, 230, "Add Monster");
    m_Window->labelfont(4);
    m_Window->user_data((void*)(this));
    { m_ValidList = new Fl_Choice(95, 70, 150, 25, "Database:");
      m_ValidList->down_box(FL_BORDER_BOX);
      m_ValidList->labelfont(4);
      m_ValidList->textfont(4);
    } // Fl_Choice* m_ValidList
    { m_CurrentList = new Fl_Choice(95, 115, 150, 25, "Current:");
      m_CurrentList->down_box(FL_BORDER_BOX);
      m_CurrentList->labelfont(4);
      m_CurrentList->textfont(4);
    } // Fl_Choice* m_CurrentList
    { Fl_Button* o = new Fl_Button(111, 190, 75, 25, "Add");
      o->labelfont(4);
      o->callback((Fl_Callback*)cb_Add);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(201, 190, 75, 25, "OK");
      o->labelfont(4);
      o->callback((Fl_Callback*)cb_OK);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(20, 190, 75, 25, "Refresh");
      o->labelfont(4);
      o->callback((Fl_Callback*)cb_Refresh);
    } // Fl_Button* o
    { m_CurrentList = new Fl_Choice(95, 25, 150, 25, "Map:");
      m_CurrentList->down_box(FL_BORDER_BOX);
      m_CurrentList->labelfont(4);
      m_CurrentList->textfont(4);
    } // Fl_Choice* m_CurrentList
    m_Window->end();
  } // Fl_Double_Window* m_Window
}

void AddMonsterWindow::ShowAll() {
  {
      m_Window->show();
  }
}

void AddMonsterWindow::AddValid(const char *szSID, const char *szName) {
  {
      m_ValidList->add(szName, 0, 0, (void *)(std::atoi(szSID)), 0);
      m_ValidList->textfont(4);
  }
}

void AddMonsterWindow::AddCurrent(const char *szSID, const char *szName) {
  {
      m_CurrentList->add(szName, 0, 0, (void *)(std::atoi(szSID)), 0);
      m_CurrentList->textfont(4);
  }
}

void AddMonsterWindow::Refresh() {
  {
      m_CurrentList->clear();
      m_ValidList->clear();
      extern SceneServer *g_SceneServer;
      if(g_SceneServer){
          g_SceneServer->UpdateValidMonsterList();
      }
      
      if(m_ValidList->size() > 0){
          m_ValidList->value(0);
      }
      
      if(m_CurrentList->size() > 0){
          m_CurrentList->value(0);
      }
  }
}
