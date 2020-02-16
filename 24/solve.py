# #!/usr/bin/env python3

solution = 24

def find_solution(cards):
    """Print equation to get 24 using card values if possible."""
    # Allowed operations (+, -, *, /, %, **)    
    values = []
    for card in cards:
        
        cards_copy = cards.copy()
        cards_copy.remove(card)
        values += solve_helper(card, cards_copy)
        
    if solution in values:
        print("Success")
    else:
        print("Failure")
        

def add(v1, v2):
    """Return the sum of the two input values"""
    return v1 + v2


def subtract(v1, v2):
    """Return the difference of the two input values"""
    return v1 - v2


def multiply(v1, v2):
    """Return the product of the two input values"""
    return v1 * v2


def divide(v1, v2):
    """Return the result of value one integer divided by value 2"""
    return v1 // v2
    

def modulo(v1, v2):
    """Return value one modulo value two"""
    return v1 % v2

def power(v1, v2):
    """Return the first value raised to the power of the second value"""
    return v1 ** v2

operations = [add, subtract, multiply, divide, modulo, power]


def solve_helper(target, cards):
    """Recusivly take in a single target card and a list of candidate cards."""    
    if len(cards) == 0:
        return [target]

    candidates = []
    for card in cards:
        for operation in operations:
            new_target = operation(target, card)
            new_cards = cards.copy()
            new_cards.remove(card)            
            candidates += solve_helper(new_target, new_cards)
   
    return candidates
         
    
if __name__ == "__main__":

    find_solution([1,2,3,4])
