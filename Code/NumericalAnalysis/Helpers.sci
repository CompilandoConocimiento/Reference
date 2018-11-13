function [result] = SameSign(a, b)
    result = sign(a) == sign(b)
endfunction

function [result] = AbsoluteDiffence(a, b)
    result = abs(abs(b) - abs(a))
endfunction

function [result] = RelativeDifference(old, new)
    result = abs(abs(new) - abs(old)) / abs(new)
endfunction

