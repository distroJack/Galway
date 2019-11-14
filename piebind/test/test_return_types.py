
import demo

def test_return_none():
	assert(demo.ReturnNone() is None)

def test_return_one():
	one = demo.ReturnOne()

def test_return_number():
	demo.ReturnNumber()

def test_return_tuple():
	one, two = demo.ReturnTuple()
