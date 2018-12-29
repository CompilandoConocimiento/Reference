

export function copyText(Text: string[]) {

    function areCommentsVisible() {
        const comment = document.querySelector(".hljs-comment") as HTMLElement
        return (comment)? comment.style.display === "none" : false
    }

    function copyTextToClipboard(text: string): void {
        const actualScroll = document.documentElement.scrollTop || document.body.scrollTop
        const textArea = document.createElement("textarea")
        textArea.value = text
        document.body.appendChild(textArea)
        textArea.focus()
        textArea.select()
        
        document.execCommand('copy')
        document.body.removeChild(textArea)
        scroll(0, actualScroll)
    }


    const realText = areCommentsVisible()? Text.map(line => line.split("//")[0]) : Text
    copyTextToClipboard(realText.join("\n"))
    M.Toast.dismissAll()
    M.toast({html: 'Code copied ;)'})
}

