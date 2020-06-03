# #!/usr/bin/env python3
import operator

solution = 24

operations = []
operations += [operator.add]
operations += [operator.sub]
operations += [operator.mul]
operations += [operator.floordiv]
operations += [operator.mod]
operations += [operator.pow]

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
    find_solution([1,1,2,10])
