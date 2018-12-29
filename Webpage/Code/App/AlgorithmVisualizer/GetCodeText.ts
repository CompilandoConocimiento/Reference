import { FilesDataResult, FilesData } from "../../Data"

const linkToBaseDirectoryToCode = "https://raw.githubusercontent.com/CompilandoConocimiento/Reference/master"

/**
   * Fetch to get the code file, then when you have it, transform it and call set state over it
   * @param TopicLink The link to the topic
   * @param filesData Information on how to transform the file
   * @param setState  The callback to send the result
   */
const getCodeText = (TopicLink: string, filesData: FilesData, setState: (x: any) => void) => {
    const baseLink = `${linkToBaseDirectoryToCode}/Code/${TopicLink}`
    const FilesDataResult: FilesDataResult = {}

    Object.entries(filesData).forEach( ([fileName, fileParts]) => {

        FilesDataResult[fileName] = []
        const codeLink = baseLink + "/" + fileName
        console.log(codeLink)
        
        fetch(codeLink)
            .then ( Data => Data.text()      )
            .then ( Text  => Text.split("\n") )
            .then ( Text  => {
                fileParts.forEach( ([start, end]) => 
                    FilesDataResult[fileName].push(Text.slice(start, end + 1))
                )
                setState({FilesDataResult})
            })
    })
}

export default getCodeText