import React from "react"

import {AlgorithmPageProps, AlgorithmData} from "../types"

export const Data: AlgorithmData = {
    name: "Binary Exponentiation",
    link: "BinaryExponentiation",
    fileNames: ["BinaryExponentiation.cpp"],
}

const BinaryExponentation: React.FunctionComponent<AlgorithmPageProps> = props => {

    return (
        <div>
            This function will performe \( {"base^{exponent}"} \) but a little bit more fast using
            exponentiation by squaring.

            <div style={{overflow: "auto"}}>
            $${`
                base ^ {exponent} = 
                \\begin{cases}
                    base \\; (base^2)^{\\; \\frac{exponent-1}{2}}   & \\text{if exponent is odd}   \\\\
                    (base^2)^{\\; \\frac{exponent}{2}}          & \\text{if exponent is even}  \\\\
                \\end{cases}
            `}$$
            </div>

            Or if you like small variable names we can say that \( base = x \) y \( exponent = n \):
            <div style={{overflow: "auto"}}>
            $${`
                x^n = 
                \\begin{cases}
                    x \\; (x^2)^{\\; \\frac{n-1}{2}}    & \\text{if n is odd}   \\\\
                    (x^2)^{\\; \\frac{n}{2}}            & \\text{if n is even}  \\\\
                \\end{cases}
            `}$$
            </div>

            Remember the bitwise operations equalities:
            <ul className="browser-default">
                <li> { "\\( x << y = x * 2^y \\)" } </li>
                <li> { "\\( x >> y = \\left \\lfloor \\dfrac{x}{2^y} \\right \\rfloor \\)" } </li>
            </ul>

            <br />
            <h6><b>How to optimize \( {"e = \\frac{e-1}{2} "} \) and \( {"e = \\frac{e}{2} "}\) </b></h6>

            This optimizations are using the bitwise operations.
            I claim that \( {"e = \\frac{e-1}{2} "} \) and \( {"e = \\frac{e}{2} "}\) are equal to
            \( {"e = e >> 1"}\).

            <br />
            <br />

            This is easy to proof, because \( {"e = e >> 1"}\) delete the least significant bit,
            so the last bit does not really matter. 
            So you find that at the end it does not matter if it is odd or even
            this will always give you the correct answer

            <br />
            <br />

            <h6><b>Check in the exponent is odd or even</b></h6>

            To do this just do exponent & 1
            <br />
                
            For example the number \(000101101010\) if the exponent 
            was odd then the last digit will be 1, so exponent & 1
            give true only if the last digit was 1.

        </div>
    )
} 


export default BinaryExponentation