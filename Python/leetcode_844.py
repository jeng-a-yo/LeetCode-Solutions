class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:

        _s = ''
        _t = ''

        for i in range(len(s)):
            if s[i] == '#':
                _s = _s[:-1]
            else:
                _s += s[i]

        for i in range(len(t)):
            if t[i] == '#':
                _t = _t[:-1]
            else:
                _t += t[i]

        return _s == _t