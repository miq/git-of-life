//////////////////////////////////////////////////////////////////////
/// @file Life_field.h
/// @author jschueths
/// @brief This is the class definition of the LifeField class.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class LifeField
/// @brief The LifeField class provides a frame and functionality
/// for the visualization of the Game of Life. 
//////////////////////////////////////////////////////////////////////
#ifndef __LIFE_FIELD_H__
#define __LIFE_FIELD_H__


#include <QApplication>
#include <QtGui>

class LifeField : public QWidget
{
  Q_OBJECT
  
  public:
    LifeField(QWidget *parent = 0);
    void setPoint(int i, int j, bool state);
    bool& operator()(int x, int y);
    const bool& operator()(const int x, const int y) const;
    
  public slots:
    void nextGeneration();
    void clear();
    void startGenerations();
    void stopGenerations();
    void setFast();
    void setNormal();
    void setSlow();
    
  protected:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    virtual void resizeEvent(QResizeEvent *e);
    void mouseHandle(const QPoint &pos, bool state);
    
  private:
    enum {MAXSIZE = 50, MINSIZE = 10, BORDER = 5};  ///< Enum for sizes
    enum {SLOW = 350, NORMAL = 150, FAST = 50};     ///< Enum for speeds
    
    bool cell[2][MAXSIZE + 2][MAXSIZE + 2];         ///< 
    int current;                                    ///< Holds which set of cells is the current generation.
    int maxi, maxj;                                 ///< Holds the maximum iteration values.
    int SCALE;                                      ///< The current scaling size.
    int pos2index(int x);
    int index2pos(int x);
    int speed;                                      ///< Holds the current speed setting.
    QTimer *genTimer;                               ///< Pointer to a QTimer used for updating the screen.
    
};
    
#endif
