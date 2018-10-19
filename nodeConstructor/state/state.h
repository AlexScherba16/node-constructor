#ifndef STATE_H
#define STATE_H


class State
{
public:
    State();    //std::unique_ptr<NodeDataModel> const &model);

    void setResizingState(bool resize)  {_resizeState = resize;}
    bool isResizing()                   {return _resizeState;}

    void setSelectedState(bool selected)    {_selectedState = selected;}
    bool isSelected()                       {return _selectedState;}

private:
    bool _resizeState;
    bool _selectedState;
};

#endif // STATE_H
