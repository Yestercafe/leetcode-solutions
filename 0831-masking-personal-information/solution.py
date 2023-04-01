class Solution:
    def isEmailAddr(self):
        return '@' in self.s

    def maskPII(self, s: str) -> str:
        self.s = s
        if self.isEmailAddr():
            name, domain = map(lambda x: x.lower(), self.s.split('@'))
            domain = domain.split('.')
            name = name[0].lower() + '*****' + name[-1].lower()
            for c in domain: c = '*'
            return name + '@' + '.'.join(domain)
        else:
            s = ''
            for c in self.s:
                if c.isdigit():
                    s += c
            l = len(s)
            if l == 10:
                return '***-***-' + s[-4:]
            elif l == 11:
                return '+*-***-***-' + s[-4:]
            elif l == 12:
                return '+**-***-***-' + s[-4:]
            else:
                return '+***-***-***-' + s[-4:]

