#pragma once


class State
{
public:
    State() :   _resizeState(false),
                _insideBoundingState(false) {}
    ~State() = default;

    void setResizingState(bool resize)          {_resizeState = resize;}
    bool isResizing()                           {return _resizeState;}

    void setInsideBoundingState(bool inside)    {_insideBoundingState = inside;}
    bool isInsideBounding()                     {return _insideBoundingState;}

private:

    bool _resizeState;
    bool _insideBoundingState;
};

