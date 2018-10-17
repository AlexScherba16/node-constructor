#ifndef STATE_H
#define STATE_H


class State
{
private:
    ReactToConnectionState _connection;
    bool _resizeState;

public:

    enum ReactToConnectionState{
          REACTING = 0,
          NOT_REACTING
    };


    State();    //std::unique_ptr<NodeDataModel> const &model);

    void setResizingState(bool resize)  {_resizeState = resize;}
    bool isResizing()                   {return _resizeState;}

};

#endif // STATE_H
