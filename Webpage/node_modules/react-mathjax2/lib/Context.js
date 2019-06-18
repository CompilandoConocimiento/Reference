'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});

var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();

var _react = require('react');

var _react2 = _interopRequireDefault(_react);

var _propTypes = require('prop-types');

var _propTypes2 = _interopRequireDefault(_propTypes);

var _loadScript = require('load-script');

var _loadScript2 = _interopRequireDefault(_loadScript);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

function _possibleConstructorReturn(self, call) { if (!self) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return call && (typeof call === "object" || typeof call === "function") ? call : self; }

function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function, not " + typeof superClass); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, enumerable: false, writable: true, configurable: true } }); if (superClass) Object.setPrototypeOf ? Object.setPrototypeOf(subClass, superClass) : subClass.__proto__ = superClass; } /* global MathJax */

/**
 * Context for loading MathJax
 */
var Context = function (_React$Component) {
  _inherits(Context, _React$Component);

  function Context(props) {
    _classCallCheck(this, Context);

    var _this = _possibleConstructorReturn(this, (Context.__proto__ || Object.getPrototypeOf(Context)).call(this, props));

    _this.state = { loaded: false };
    _this.onLoad = _this.onLoad.bind(_this);
    return _this;
  }

  _createClass(Context, [{
    key: 'getChildContext',
    value: function getChildContext() {
      return {
        MathJax: typeof MathJax === 'undefined' ? undefined : MathJax,
        input: this.props.input
      };
    }
  }, {
    key: 'componentDidMount',
    value: function componentDidMount() {
      var script = this.props.script;

      if (!script) {
        return this.onLoad();
      }

      (0, _loadScript2.default)(script, this.onLoad);
    }
  }, {
    key: 'onLoad',
    value: function onLoad() {
      var _this2 = this;

      var options = this.props.options;

      MathJax.Hub.Config(options);

      MathJax.Hub.Register.StartupHook('End', function () {
        MathJax.Hub.processSectionDelay = _this2.props.delay;

        if (_this2.props.didFinishTypeset) {
          _this2.props.didFinishTypeset();
        }

        if (_this2.props.onLoad) {
          _this2.props.onLoad();
        }

        _this2.setState({
          loaded: true
        });
      });

      MathJax.Hub.Register.MessageHook("Math Processing Error", function (message) {
        if (_this2.props.onError) {
          _this2.props.onError(MathJax, message);
        }
      });
    }
  }, {
    key: 'render',
    value: function render() {
      if (!this.state.loaded && !this.props.noGate) {
        return this.props.loading;
      }

      var children = this.props.children;

      return _react2.default.Children.only(children);
    }
  }]);

  return Context;
}(_react2.default.Component);

Context.propTypes = {
  children: _propTypes2.default.node.isRequired,
  didFinishTypeset: _propTypes2.default.func,
  script: _propTypes2.default.oneOfType([_propTypes2.default.string, _propTypes2.default.oneOf([false])]),
  input: _propTypes2.default.oneOf(['ascii', 'tex']),
  delay: _propTypes2.default.number,
  options: _propTypes2.default.object,
  loading: _propTypes2.default.node,
  noGate: _propTypes2.default.bool
};

Context.childContextTypes = {
  MathJax: _propTypes2.default.object,
  input: _propTypes2.default.string
};

Context.defaultProps = {
  script: 'https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-MML-AM_CHTML',
  input: 'ascii',
  delay: 0,
  options: {},
  loading: null,
  noGate: false
};

exports.default = Context;