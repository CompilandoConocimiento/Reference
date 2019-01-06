import React from "react"

export const LaTeX: React.FunctionComponent = props => (
    <div style={{overflow: "auto"}}>
        $${`${props.children}`}$$
    </div>
)