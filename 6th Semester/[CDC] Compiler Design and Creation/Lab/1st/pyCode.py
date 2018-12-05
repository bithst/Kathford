operand = [chr(x) for x in range(ord('a'), ord('z') + 1)] + [chr(x) for x in range(ord('0'), ord('9') + 1)] + [chr(x) for x in range(ord('A'), ord('Z') + 1)]

operator = {'(': 0, '+': 1, '-': 1, '/': 2, '*': 2}

postfix_stack = []
postfix = []

print("Enter a algebraic equation:")
equation = input()

for char in equation:
  ch = char.upper()

  if ch == '(':
    postfix_stack.append(char)
  elif ch == ')':
    while postfix_stack[-1] != '(':
      postfix.append(postfix_stack.pop())
    postfix_stack.pop()
  elif ch in operand:
    postfix.append(char)
  elif ch in operator.keys():
    while len(postfix_stack) != 0 and operator[ch] <= operator[postfix_stack[-1]]:
      postfix.append(postfix_stack.pop())
    postfix_stack.append(char)

while len(postfix_stack) != 0:
  postfix.append(postfix_stack.pop())

print(''.join(postfix))