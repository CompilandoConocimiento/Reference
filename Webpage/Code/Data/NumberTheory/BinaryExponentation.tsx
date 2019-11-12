import React, { FunctionComponent } from "react"

import { Typography, Box } from "@material-ui/core"
import { InlineMath, BlockMath } from "react-katex"

import Code from "../../App/AlgorithmVisualizer/ShowCode"

const Component: FunctionComponent = () => {
  return (
    <div>
      <Typography gutterBottom variant="h5">
        <Box fontWeight={800}>Definition</Box>
      </Typography>

      <p>
        This function will performe <InlineMath math="base^{exponent}" /> but a lot faster; this
        will not do the obvious "<InlineMath math="base * base * base * base ..." />" and so on
        <InlineMath math="exponent" /> times but rather just <InlineMath math="log(exponent)" />{" "}
        operations. This technique is called exponentiation by squaring.
      </p>

      <p>The idea is to see this way of expressing exponentiation:</p>

      <BlockMath>
        {String.raw`
            base ^ {exponent} = 
            \begin{cases}
            (base^2)^{\space \frac{exponent}{2}}             & \text{if exponent is even}  \\
            base \space (base^2)^{\space \frac{exponent-1}{2}}   & \text{if exponent is odd}   \\
            \end{cases}
        `}
      </BlockMath>
      <p>
        Or if you like small variable names we can say that <InlineMath math="base = x" /> and{" "}
        <InlineMath math="exponent = n" />:
      </p>
      <BlockMath>
        {String.raw`
            x^n = 
            \begin{cases}
            (x^2)^{\space \frac{n}{2}}           & \text{if n is even}  \\
            x \space (x^2)^{\space \frac{n-1}{2}}    & \text{if n is odd}   \\
            \end{cases}
        `}
      </BlockMath>

      <Code language={"cpp"} fileName={"BinaryExponentiation.cpp"} lines={[1, 8]} />

      <Typography gutterBottom variant="h5">
        <Box fontWeight={800}>Simple Optimizations</Box>
      </Typography>

      <p>Now we want to eliminate the recursion and modify a little bit the idea:</p>
      <ul>
        <li style={{ marginBottom: "0.7rem" }}>
          <p>
            Instead of making a recursive function we will do an iterative function, to do this we
            use a while loop with the stop condition being when the exponent is 0; this represents
            that we have made all the operations necessary so we can just safely return{" "}
            <InlineMath math="solution" />.
          </p>
        </li>
        <li style={{ marginBottom: "0.7rem" }}>
          <p>
            In general the base in the next recursive call will be square of the current one, so we
            do that.
          </p>
        </li>
        <li style={{ marginBottom: "0.7rem" }}>
          <p>
            Also remember that <InlineMath math="\frac{exponent}{2}" /> is doing a integer division,
            so in reality it is doing <InlineMath math="\lfloor \frac{exponent}{2} \rfloor" /> and
            that is exaclty what we wanted because it handles correctly both cases, odd and even
            exponent.
          </p>
        </li>
        <li style={{ marginBottom: "0.7rem" }}>
          <p>
            Now, the special part here is when the exponent is odd, in this case remember the
            expression <InlineMath math="x^n = x \space (x^2)^{\space \frac{n-1}{2}}" />.
          </p>

          <p>
            So now, we have to keep in mind we need to multiply the result of the next consecutive
            recursive calls by the current exponent, so we need a place to store those bases, we are
            going to use <InlineMath math="solution" /> for that.
          </p>
        </li>
        <li>
          Finally you may be thinking the same thing as me: what happen if we have a exponent of the
          form <InlineMath math="2^n" /> so there are never odd exponents and therefore we never
          update the solution?
          <br />
          Well, remember that <InlineMath math="2^3 = 8 = 1 * 8" />, or more in general{" "}
          <InlineMath math="2^n = 1 * 2^n" />, so we will eventually update solution, when we reach{" "}
          <InlineMath math="exponent = 1" />.
        </li>
      </ul>

      <Code language={"cpp"} fileName={"BinaryExponentiation.cpp"} lines={[10, 26]} />

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

      <Code language={"cpp"} fileName={"BinaryExponentiation.cpp"} lines={[28, 40]} />

      <Typography gutterBottom variant="h5">
        <Box fontWeight={800}>Modular Exponentation</Box>
      </Typography>

      <p>
        This is to do <InlineMath math="base^{exponent}  \space \space \mod \space n" />
      </p>

      <Code language={"cpp"} fileName={"BinaryExponentiation.cpp"} lines={[42, 56]} />
    </div>
  )
}

export default Component
