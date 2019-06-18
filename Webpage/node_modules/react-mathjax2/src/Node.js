import React from 'react'
import PropTypes from 'prop-types'

const types = {
  ascii: 'asciimath',
  tex: 'tex'
}

class Node extends React.Component {
  /**
   * Render the math once the node is mounted
   */
  componentDidMount() {
    this.typeset()
  }

  /**
   * Update the jax, force update if the display mode changed
   */
  componentDidUpdate(prevProps) {
    const forceUpdate = prevProps.inline !== this.props.inline || prevProps.children !== this.props.children
    this.typeset(forceUpdate)
  }

  /**
   * Prevent update when the source has not changed
   */
  shouldComponentUpdate(nextProps, nextState, nextContext) {
    return (
      nextProps.children !== this.props.children ||
      nextProps.inline !== this.props.inline
    )
  }

  /**
   * Clear the math when unmounting the node
   */
  componentWillUnmount() {
    this.clear()
  }

  /**
   * Clear the jax
   */
  clear() {
    const MathJax = this.context.MathJax

    if (!this.script) {
      return
    }

    const jax = MathJax.Hub.getJaxFor(this.script)

    if (jax) {
      jax.Remove()
    }
  }

  /**
   * Update math in the node
   * @param { Boolean } forceUpdate
   */
  typeset(forceUpdate) {
    const { MathJax } = this.context

    if (!MathJax) {
      throw Error("Could not find MathJax while attempting typeset! Probably MathJax script hasn't been loaded or MathJax.Context is not in the hierarchy")
    }

    const text = this.props.children

    if (forceUpdate) {
      this.clear()
    }

    if (forceUpdate || !this.script) {
      this.setScriptText(text)
    }

    MathJax.Hub.Queue(
      MathJax.Hub.Reprocess(this.script, this.props.onRender)
    );
  }

  /**
   * Create a script
   * @param { String } text
   */
  setScriptText(text) {
    const inline = this.props.inline
    const type = types[this.context.input]
    if (!this.script) {
      this.script = document.createElement('script')
      this.script.type = `math/${type}; ${inline ? '' : 'mode=display'}`
      this.refs.node.appendChild(this.script)
    }

    if ('text' in this.script) {
      // IE8, etc
      this.script.text = text
    } else {
      this.script.textContent = text
    }
  }

  render() {
    return React.createElement('span', { ref: 'node' })
  }
}

Node.propTypes = {
  inline: PropTypes.bool,
  children: PropTypes.node.isRequired,
  onRender: PropTypes.func
}

Node.contextTypes = {
  MathJax: PropTypes.object,
  input: PropTypes.string
}

Node.defaultProps = {
  inline: false,
  onRender: function onRender() {}
}

export default Node
