class Solution:
    def encode(self, strs: List[str]) -> str:
        # handle edge case
        if not strs: return ""

        # variable holding result
        res = ""
        
        # format: number//delimiter//string
        for s in strs:
            res += str(len(s)) + "#" + s
        return res

    def decode(self, s: str) -> List[str]:
        # handle edge case
        if not s: return []

        # resulting list array, and i variable
        res, i = [], 0
        while i < len(s):
            j = i
            while s[j] != '#':
                j += 1
            length = int(s[i:j]) # gives us the number in front of #
            res.append(s[j+1:j+1+length]) #appending string from index
                                          #of pound + 1 and the next length characters
            i = j + 1 + length # increment the counter
        return res
