
import demo

def test_return_none():
	assert(demo.ReturnNone() is None)

def test_return_one():
	one = demo.ReturnOne()

def test_return_number():
	demo.ReturnNumber()

def test_return_tuple():
	assert(isinstance(demo.ReturnTuple(), tuple))

def test_return_list():
	assert(isinstance(demo.ReturnList(), list))

def test_return_string():
	assert(isinstance(demo.ReturnString(), str))
