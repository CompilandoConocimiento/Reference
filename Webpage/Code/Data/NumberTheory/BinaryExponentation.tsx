import React from "react"
import { AlgorithmPageProps, AlgorithmPageInformation } from "../types"
import ShowCode from "../../App/AlgorithmVisualizer/ShowCode"
import { LaTeX } from "../../App/AlgorithmVisualizer/LaTeX"

const PageConfig: AlgorithmPageInformation = {
    filesData: {
        "BinaryExponentiation.cpp": [  [9, 20], [22, 30], [33, 45] ]
    },
    CodeConfig: {
        CodeStyles: { fontSize: 0.6, backgroundColor: "#2b2b2b" },
        CodeActions: {},
    }
}

const BinaryExponentation: React.FunctionComponent<AlgorithmPageProps> = ({filesData}) => {
    return (
        <div>
            This function will performe \( {"base^{exponent}"} \) but a little bit more fast using
            exponentiation by squaring.
            The idea is to see this way of expressing exponentiation:
            <LaTeX>
                {String.raw`
                    base ^ {exponent} = 
                    \begin{cases}
                    (base^2)^{\; \frac{exponent}{2}}             & \text{if exponent is even}  \\
                    base \; (base^2)^{\; \frac{exponent-1}{2}}   & \text{if exponent is odd}   \\
                    \end{cases}
                `}  
            </LaTeX>

            Or if you like small variable names we can say that \( base = x \) y \( exponent = n \):
            <LaTeX>
                {String.raw`
                    x^n = 
                    \begin{cases}
                    (x^2)^{\; \frac{n}{2}}           & \text{if n is even}  \\
                    x \; (x^2)^{\; \frac{n-1}{2}}    & \text{if n is odd}   \\
                    \end{cases}
                `}  
            </LaTeX>

            Remember the bitwise operations equalities:
            <ul className="browser-default">
                <li> { "\\( x << y = x * 2^y \\)" } </li>
                <li> { "\\( x >> y = \\left \\lfloor \\dfrac{x}{2^y} \\right \\rfloor \\)" } </li>
            </ul>

            <br />
            <h6><b>How to optimize \( {"e = \\frac{e-1}{2} "} \) and \( {"e = \\frac{e}{2} "}\) </b></h6>

            This optimizations are using the bitwise operations.
            I claim that 
            \( {"e = \\frac{e-1}{2} "} \) and \( {"e = \\frac{e}{2} "}\) are equal to
            \( {"e = e >> 1"}\).

            <br />
            <br />

            This is easy to proof, because \( {"e = e >> 1"}\) delete the least significant bit,
            so the last bit does not really matter. 
            So you find that at the end it does not matter if it is odd or even
            this will always give you the correct answer.

            <br />
            <br />

            <h6><b>Check in the exponent is odd or even</b></h6>

            To do this just do exponent & 1
            <br />
                
            For example the number \(000101101010\) if the exponent 
            was odd then the last digit will be 1, so exponent & 1
            give true only if the last digit was 1.

            <ShowCode 
                ID={"Show1"}
                Data = {filesData}
                fileName={"BinaryExponentiation.cpp"}
                partOfFile={0}
            />

            <ShowCode 
                ID={"Show2"}
                Data = {filesData}
                fileName={"BinaryExponentiation.cpp"}
                partOfFile={1}
            />

            <ShowCode 
                ID={"Show"}
                Data = {filesData}
                fileName={"BinaryExponentiation.cpp"}
                partOfFile={2}
            />

        </div>
    )
} 

export default { Config: PageConfig, Component: BinaryExponentation }