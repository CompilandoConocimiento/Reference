/**
 * Copy code fragment to clipboard
 * @param Text The code fragment
 */
const copyText = (Text: Array<string>) => {
  function areCommentsVisible() {
    const comment = document.querySelector(".hljs-comment") as HTMLElement
    return comment ? comment.style.display === "none" : false
  }

  function copyTextToClipboard(text: string) {
    const actualScroll = document.documentElement.scrollTop || document.body.scrollTop
    const textArea = document.createElement("textarea")
    textArea.value = text
    document.body.appendChild(textArea)
    textArea.focus()
    textArea.select()

    document.execCommand("copy")
    document.body.removeChild(textArea)
    scroll(0, actualScroll)
  }

  const realText = areCommentsVisible() ? Text.map(line => line.split("//")[0]) : Text
  copyTextToClipboard(realText.join("\n"))
}

export default copyText
