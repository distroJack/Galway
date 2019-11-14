
import demo

def test_accept_zero():
    try:
        demo.AcceptZero(1)
    except TypeError:
        pass
    else:
        assert(False) # accept zero accepted more than one parameter"

def test_accept_one():
    demo.AcceptOne(1)

def test_accept_keyword():
    demo.AcceptKeyword(n=1)
