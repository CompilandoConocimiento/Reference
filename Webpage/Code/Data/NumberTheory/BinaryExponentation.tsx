import React, { FunctionComponent } from "react"

import { Typography, Box } from "@material-ui/core"
import { InlineMath, BlockMath } from "react-katex"

import SyntaxHighlighter from "react-syntax-highlighter"
import { rainbow } from "react-syntax-highlighter/dist/esm/styles/hljs"

const Component: FunctionComponent = () => {
  return (
    <div>
      <Typography gutterBottom variant="h5">
        <Box fontWeight={800}>Definition</Box>
      </Typography>

      <p>
        This function will performe <InlineMath math="base^{exponent}" /> but a little bit more fast
        using exponentiation by squaring. The idea is to see this way of expressing exponentiation:
      </p>
      <BlockMath>
        {String.raw`
            base ^ {exponent} = 
            \begin{cases}
            (base^2)^{\; \frac{exponent}{2}}             & \text{if exponent is even}  \\
            base \; (base^2)^{\; \frac{exponent-1}{2}}   & \text{if exponent is odd}   \\
            \end{cases}
        `}
      </BlockMath>
      <p>
        Or if you like small variable names we can say that <InlineMath math="base = x" /> y{" "}
        <InlineMath math="exponent = n" />:
      </p>
      <BlockMath>
        {String.raw`
            x^n = 
            \begin{cases}
            (x^2)^{\; \frac{n}{2}}           & \text{if n is even}  \\
            x \; (x^2)^{\; \frac{n-1}{2}}    & \text{if n is odd}   \\
            \end{cases}
        `}
      </BlockMath>

      <SyntaxHighlighter
        language="javascript"
        style={rainbow}
        customStyle={{
          padding: "1.2rem",
          marginTop: "1.5rem",
          marginBottom: "1.5rem",
          borderRadius: "0.8rem",
          boxShadow: "0 1px 3px rgba(0,0,0,0.12), 0 1px 2px rgba(0,0,0,0.24)",
        }}
      >
        {`template <typename integer, typename unsignedInteger>
integer RecursiveBinaryExp (integer x, unsignedInteger n) {
    if (n == 0) return 1;                                         
    if (n == 1) return x;                                           

    if (n % 2 == 0) return RecursiveBinaryExp(x * x,  n / 2);           
    else return (x * RecursiveBinaryExp(x * x, (n-1) / 2));  
} 
        `}
      </SyntaxHighlighter>

      <Typography gutterBottom variant="h5">
        <Box fontWeight={800}>Simple Optimizations</Box>
      </Typography>

      <p>Now we want to eliminate the recursion and modify a little bit the idea:</p>
      <ul>
        <li>
          If exponent is odd, first do <InlineMath math="solution = base * solution" />, now, we
          have to delete 1 to the exponent, so the exponent is even, so we can just say that the
          base is <InlineMath math="base = base^2" /> and that the exponent is just the half of the
          original exponent.
        </li>
        <li>
          If exponent is even, so we can just say that the base is{" "}
          <InlineMath math="base = base^2" /> and that the exponent is just the half of the original
          exponent.
        </li>
      </ul>

      <Typography gutterBottom variant="h5">
        <Box fontWeight={800}>Optimizations</Box>
      </Typography>

      <Typography gutterBottom variant="subtitle1">
        <Box fontWeight={600}>
          How to optimize <InlineMath math="e = \frac{e-1}{2}" /> and{" "}
          <InlineMath math="e = \frac{e}{2}" />
        </Box>
      </Typography>

      <p>Remember the bitwise operations equalities:</p>
      <ul>
        <li>
          <InlineMath math="x << y = x * 2^y" />
        </li>
        <li>
          <InlineMath math="x >> y = \left \lfloor \dfrac{x}{2^y} \right \rfloor" />
        </li>
      </ul>
      <p>
        This optimizations are using the bitwise operations. I claim that{" "}
        <InlineMath math="e = \frac{e-1}{2}" /> and <InlineMath math="e = \frac{e}{2}" /> are equal
        to <InlineMath math="e = e >> 1" />
      </p>
      <p>
        This is easy to proof, because <InlineMath math="e = e >> 1" /> delete the least significant
        bit, so the last bit does not really matter. So you find that at the end it does not matter
        if it is odd or even this will always give you the correct answer.
      </p>

      <Typography gutterBottom variant="subtitle1">
        <Box fontWeight={600}>Check in the exponent is odd or even</Box>
      </Typography>

      <p>To do this just do exponent & 1.</p>
      <p>
        For example the number <InlineMath math="000101101010" /> if the exponent was odd then the
        last digit will be 1, so exponent & 1 give true only if the last digit was 1.
      </p>

      <Typography gutterBottom variant="h5">
        <Box fontWeight={800}>Modular Exponentation</Box>
      </Typography>

      <p>
        This is to do <InlineMath math="base^{exponent} \mod n" />
      </p>
    </div>
  )
}

export default Component
