print('Enter an equation: ')
equation = input()

operand = [chr(x) for x in range(ord('a'), ord('z') + 1)] + [chr(x) for x in range(ord('0'), ord('9') + 1)] + [chr(x) for x in range(ord('A'), ord('Z') + 1)]
operator = {'(': 0, '+': 1, '-': 1, '/': 2, '*': 2}

postfix_stack = []
postfix = []

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

tac = {}
tac_stack = []
count = 1

for item in postfix:
  if item in '+-*/':
    temp = []
    var = 'T' + str(count)
    
    temp.append(tac_stack.pop(0))
    temp.append(item)
    temp.append(tac_stack.pop(0))
    tac_stack.insert(0, var)
    tac[var] = list(reversed(temp))
    count += 1
  else:
    tac_stack.insert(0, item)

for i in range(len(tac)):
  print('T{} = {}'.format(i+1, ' '.join(tac['T' + str(i+1)])))