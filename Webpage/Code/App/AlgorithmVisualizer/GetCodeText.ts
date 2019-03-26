import { FilesDataResult, FilesData } from "../../Data"

/**
 * Fetch to get the code file, then when you have it, transform it and call set state over it
 * @param baseLink The base link to the server where are the files
 * @param filesData Information on how to transform the file
 * @param setState  The callback to send the result
 */
const getCodeText = (baseLink: string, filesData: FilesData, setState: (x: any) => void) => {
  const FilesDataResult: FilesDataResult = {}

  Object.entries(filesData).forEach(([fileName, fileParts]) => {
    FilesDataResult[fileName] = {}
    const codeLink = baseLink + "/" + fileName
    console.log(codeLink)

    fetch(codeLink)
      .then(Data => Data.text())
      .then(Text => Text.split("\n"))
      .then(Text => {
        fileParts.forEach(filePart => {
          const name = filePart.name
          const [start, end] = filePart.parts
          FilesDataResult[fileName][name] = Text.slice(start - 1, end)
        })

        setState(FilesDataResult)
      })
  })
}

export default getCodeText
