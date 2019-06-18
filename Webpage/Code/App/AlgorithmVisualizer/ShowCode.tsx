import React, { FunctionComponent, useContext } from "react"
import SyntaxHighlighter from "react-syntax-highlighter"

import { Loading } from "../Helpers"
import { CodeDataContext, CodeStyleContext } from "../AlgorithmVisualizer"
import { baseCodeStyle, getCodeStyle } from "./Styles"

type CodeType = FunctionComponent<{ language: string; fileName: string; lines: [number, number] }>
const Code: CodeType = ({ language, fileName, lines }) => {
  const codeStyle = useContext(CodeStyleContext)
  const [codeData, getCodeFile] = useContext(CodeDataContext)

  if (codeData[fileName] === undefined) {
    getCodeFile(fileName)
    return <Loading />
  }

  const [start, end] = lines
  const codeText = codeData[fileName].slice(start - 1, end).join("\n")
  const style = getCodeStyle(codeStyle.style)
  const customStyle = { ...baseCodeStyle, fontSize: codeStyle.fontSize }

  return <SyntaxHighlighter {...{ customStyle, language, style }}>{codeText}</SyntaxHighlighter>
}

export default Code
