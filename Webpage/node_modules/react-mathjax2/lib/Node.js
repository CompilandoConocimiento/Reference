'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});

var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();

var _react = require('react');

var _react2 = _interopRequireDefault(_react);

var _propTypes = require('prop-types');

var _propTypes2 = _interopRequireDefault(_propTypes);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

function _possibleConstructorReturn(self, call) { if (!self) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return call && (typeof call === "object" || typeof call === "function") ? call : self; }

function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function, not " + typeof superClass); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, enumerable: false, writable: true, configurable: true } }); if (superClass) Object.setPrototypeOf ? Object.setPrototypeOf(subClass, superClass) : subClass.__proto__ = superClass; }

var types = {
  ascii: 'asciimath',
  tex: 'tex'
};

var Node = function (_React$Component) {
  _inherits(Node, _React$Component);

  function Node() {
    _classCallCheck(this, Node);

    return _possibleConstructorReturn(this, (Node.__proto__ || Object.getPrototypeOf(Node)).apply(this, arguments));
  }

  _createClass(Node, [{
    key: 'componentDidMount',

    /**
     * Render the math once the node is mounted
     */
    value: function componentDidMount() {
      this.typeset();
    }

    /**
     * Update the jax, force update if the display mode changed
     */

  }, {
    key: 'componentDidUpdate',
    value: function componentDidUpdate(prevProps) {
      var forceUpdate = prevProps.inline !== this.props.inline || prevProps.children !== this.props.children;
      this.typeset(forceUpdate);
    }

    /**
     * Prevent update when the source has not changed
     */

  }, {
    key: 'shouldComponentUpdate',
    value: function shouldComponentUpdate(nextProps, nextState, nextContext) {
      return nextProps.children !== this.props.children || nextProps.inline !== this.props.inline;
    }

    /**
     * Clear the math when unmounting the node
     */

  }, {
    key: 'componentWillUnmount',
    value: function componentWillUnmount() {
      this.clear();
    }

    /**
     * Clear the jax
     */

  }, {
    key: 'clear',
    value: function clear() {
      var MathJax = this.context.MathJax;

      if (!this.script) {
        return;
      }

      var jax = MathJax.Hub.getJaxFor(this.script);

      if (jax) {
        jax.Remove();
      }
    }

    /**
     * Update math in the node
     * @param { Boolean } forceUpdate
     */

  }, {
    key: 'typeset',
    value: function typeset(forceUpdate) {
      var MathJax = this.context.MathJax;


      if (!MathJax) {
        throw Error("Could not find MathJax while attempting typeset! Probably MathJax script hasn't been loaded or MathJax.Context is not in the hierarchy");
      }

      var text = this.props.children;

      if (forceUpdate) {
        this.clear();
      }

      if (forceUpdate || !this.script) {
        this.setScriptText(text);
      }

      MathJax.Hub.Queue(MathJax.Hub.Reprocess(this.script, this.props.onRender));
    }

    /**
     * Create a script
     * @param { String } text
     */

  }, {
    key: 'setScriptText',
    value: function setScriptText(text) {
      var inline = this.props.inline;
      var type = types[this.context.input];
      if (!this.script) {
        this.script = document.createElement('script');
        this.script.type = 'math/' + type + '; ' + (inline ? '' : 'mode=display');
        this.refs.node.appendChild(this.script);
      }

      if ('text' in this.script) {
        // IE8, etc
        this.script.text = text;
      } else {
        this.script.textContent = text;
      }
    }
  }, {
    key: 'render',
    value: function render() {
      return _react2.default.createElement('span', { ref: 'node' });
    }
  }]);

  return Node;
}(_react2.default.Component);

Node.propTypes = {
  inline: _propTypes2.default.bool,
  children: _propTypes2.default.node.isRequired,
  onRender: _propTypes2.default.func
};

Node.contextTypes = {
  MathJax: _propTypes2.default.object,
  input: _propTypes2.default.string
};

Node.defaultProps = {
  inline: false,
  onRender: function onRender() {}
};

exports.default = Node;