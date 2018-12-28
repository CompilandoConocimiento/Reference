import { Topic } from "./types";

const SaveData = (Topics: Array<Topic>, fileName: string) => {

    const a = document.createElement("a")
    a.setAttribute("style", "display: none")
    document.body.appendChild(a)

    console.log(Topics)

    const Directory = Topics.map (
        Topic => ({
            name: Topic.name,
            link: Topic.link,
            subTopics: Topic.subTopics.map( subTopic => ({
                name: subTopic.name,
                link: subTopic.link
            }))
        })
    )

    const data = JSON.stringify(Directory, null, 2),
    blob = new Blob([data], {type: "octet/stream"}),
    url = window.URL.createObjectURL(blob)
    a.href = url
    a.download = fileName
    a.click()
    window.URL.revokeObjectURL(url)
}

export default SaveData
