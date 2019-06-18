import React, { FunctionComponent, useContext } from "react"

import SyntaxHighlighter from "react-syntax-highlighter"
import { agate } from "react-syntax-highlighter/dist/esm/styles/hljs"

import { Loading } from "../Helpers"

import { CodeDataContext, LinkContext } from "./index"

const Styles = {
  padding: "1.2rem",
  marginTop: "1.5rem",
  marginBottom: "1.5rem",
  borderRadius: "0.8rem",
  boxShadow: "0 1px 3px rgba(0,0,0,0.12), 0 1px 2px rgba(0,0,0,0.24)",
}

const Code: FunctionComponent<{ language: string; fileName: string; lines: [number, number] }> = ({
  language,
  fileName,
  lines,
}) => {
  const [CodeData, changeCodeData] = useContext(CodeDataContext)
  const baseLink = useContext(LinkContext)
  const [start, end] = lines

  if (CodeData[fileName] === undefined) {
    const linkToFile = baseLink + "/" + fileName
    fetch(linkToFile)
      .then(response => response.text())
      .then(text => text.split("\n"))
      .then(lines =>
        changeCodeData(codeData => {
          const newData = { ...codeData }
          newData[fileName] = lines
          return newData
        })
      )

    return <Loading />
  }

  const codeText = CodeData[fileName].slice(start - 1, end).join("\n")

  return (
    <SyntaxHighlighter language={language} style={agate} customStyle={Styles}>
      {codeText}
    </SyntaxHighlighter>
  )
}

export default Code
