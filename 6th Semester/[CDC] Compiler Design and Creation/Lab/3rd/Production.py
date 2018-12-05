class Production():
  _rules = []
  _nonTerminals = {}
  _terms = {}

  def __init__(self, rules):
    for item in rules:
      if self._checkRule(item) == True:
        self._rules.append(item)
      else:
        raise ValueError('Invalid data!')
    self._calculate()

  def _calcPredictiveParsingTable (self):
    for (left, right) in self._rules:
      if '#' in self._terms[right[0]]['first']:
        for term in self._terms[left]['follow']:
          self._nonTerminals[left][term] = '{}->{}'.format(left, right)
          if '$' in self._terms[left]['follow']:
            self._nonTerminals[left]['$'] = '{}->{}'.format(left, right)
      else:
        for term in self._terms[right[0]]['first']:
          self._nonTerminals[left][term] = '{}->{}'.format(left, right)

  def _startSymbol(self):
    if len(self._rules) > 0:
      return self._rules[0][0]
    else:
      return None

  def _calculate(self):
    self._calcNonTerminals()
    self._calcTerms()
    for term in self._terms.keys():
      self._calcFirsts(term)
    for term in self._terms.keys():
      self._calcFollows(term)   
    self._calcPredictiveParsingTable() 

  def _calcTerms(self):
    for term in list(set(''.join([left + right for (left, right) in self._rules]))):
      self._terms[term] = {}

  def _calcNonTerminals(self):
    for nonTerminal in [left for (left, right) in self._rules]:
      self._nonTerminals[nonTerminal] = {}

  def _checkRule(self, rule):
    return (type(rule) == tuple and len(rule) == 2)

  def _calcFirsts(self, term):
    if 'first' in self._terms[term].keys():
      return self._terms[term]['first']

    self._terms[term]['first'] = []

    if term not in self._nonTerminals:
      self._terms[term]['first'].extend(term)
      return self._terms[term]['first']

    for (left, right) in self._rules:
      if left == term:
        for symbol in right:
          if symbol == '#':
            self._terms[term]['first'].extend('#')
            break
          self._terms
          if '#' not in self._calcFirsts(symbol):
            self._terms[term]['first'].extend(self._calcFirsts(symbol))
            break
          self._terms[term]['first'].extend(self._terms[symbol]['first'][:].remove('#'))

    return self._terms[term]['first']
    
  def _calcFollows(self, term):
    if 'follow' in self._terms[term].keys():
      return self._terms[term]['follow']

    self._terms[term]['follow'] = []

    if term == self._rules[0][0]:
      self._terms[term]['follow'].extend('$')

    for (left, right) in self._rules:
      if term in right:
        termIndex = right.index(term)
        followIndex = termIndex + 1
        while True:
          if followIndex == len(right):
            if left != term:
              self._terms[term]['follow'].extend(self._calcFollows(left))
            break
          
          if '#' not in self._terms[right[followIndex]]['first']:
            self._terms[term]['follow'].extend(self._terms[right[followIndex]]['first'])
            break
          
          self._terms[term]['follow'].extend([char for char in self._terms[right[followIndex]]['first'] if char != '#'])
          followIndex += 1

        return self._terms[term]['follow'] 

  def showFirstAndFollow (self):
    strn = ''
    strn += '{:<7}{:<20}{:<20}\n'.format('VALUE', 'FIRST', 'FOLLOW')
    for key in self._terms.keys():
      if key in self._nonTerminals:
        strn += '{:<7}{:<20}{:<20}\n'.format(key, str(self._terms[key]['first']), str(self._terms[key]['follow']))
    return strn

  def showParsingTable(self):
    terminals = [X for X in self._terms if X != '#' and X not in self._nonTerminals.keys()]
    length = len(terminals) + 1
    strn = ('{:_^{width}}\n'.format('INPUT SYMBOL (TERMINAL)', width=length*15))
    strn += '{:<15}'.format('NON-TERMINAL')
    for item in terminals:
      strn += '{:<15}'.format(item)
    strn += '\n'
    for key in self._nonTerminals:
      strn += '{:<15}'.format(key)
      for item in terminals:
        if item in self._nonTerminals[key].keys():
          strn += '{:<15}'.format(self._nonTerminals[key][item])
        else:
          strn += '{:<15}'.format('-')
      strn += '\n'

    return strn