import React from 'react';
import PropTypes from 'prop-types' ;

class Text extends React.Component {
  componentDidMount() {
    this.refreshMathJax();
  }

  componentDidUpdate() {
    this.refreshMathJax();
  }

  refreshMathJax() {
    const { MathJax } = this.context;
    if (!MathJax) {
      throw Error("Could not find MathJax while attempting typeset! Probably MathJax script hasn't been loaded or MathJax.Context is not in the hierarchy")
    }

    MathJax.Hub.Queue(
      MathJax.Hub.Typeset(this.div, this.props.onRender)
    );
  }

  render() {
    const { classes, options } = this.props;

    return (
      <div key={ this.props.text } ref={ (div) => this.div = div }>
        { this.props.text }
      </div>
    );
  }
}

Text.contextTypes = {
  MathJax: PropTypes.object,
};

export default Text;