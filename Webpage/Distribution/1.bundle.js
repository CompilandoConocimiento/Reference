(window["webpackJsonp"] = window["webpackJsonp"] || []).push([[1],{

/***/ "./Code/App/AlgorithmVisualizer/ShowCode.tsx":
/*!***************************************************!*\
  !*** ./Code/App/AlgorithmVisualizer/ShowCode.tsx ***!
  \***************************************************/
/*! exports provided: default */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
eval("__webpack_require__.r(__webpack_exports__);\n/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! react */ \"./node_modules/react/index.js\");\n/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_0__);\n/* harmony import */ var react_syntax_highlighter__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! react-syntax-highlighter */ \"./node_modules/react-syntax-highlighter/dist/esm/index.js\");\n/* harmony import */ var _Helpers__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ../Helpers */ \"./Code/App/Helpers.tsx\");\n/* harmony import */ var _AlgorithmVisualizer__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ../AlgorithmVisualizer */ \"./Code/App/AlgorithmVisualizer/index.tsx\");\n/* harmony import */ var _Styles__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! ./Styles */ \"./Code/App/AlgorithmVisualizer/Styles.ts\");\nfunction _objectSpread(target) { for (var i = 1; i < arguments.length; i++) { var source = arguments[i] != null ? arguments[i] : {}; var ownKeys = Object.keys(source); if (typeof Object.getOwnPropertySymbols === 'function') { ownKeys = ownKeys.concat(Object.getOwnPropertySymbols(source).filter(function (sym) { return Object.getOwnPropertyDescriptor(source, sym).enumerable; })); } ownKeys.forEach(function (key) { _defineProperty(target, key, source[key]); }); } return target; }\n\nfunction _defineProperty(obj, key, value) { if (key in obj) { Object.defineProperty(obj, key, { value: value, enumerable: true, configurable: true, writable: true }); } else { obj[key] = value; } return obj; }\n\nfunction _slicedToArray(arr, i) { return _arrayWithHoles(arr) || _iterableToArrayLimit(arr, i) || _nonIterableRest(); }\n\nfunction _nonIterableRest() { throw new TypeError(\"Invalid attempt to destructure non-iterable instance\"); }\n\nfunction _iterableToArrayLimit(arr, i) { var _arr = []; var _n = true; var _d = false; var _e = undefined; try { for (var _i = arr[Symbol.iterator](), _s; !(_n = (_s = _i.next()).done); _n = true) { _arr.push(_s.value); if (i && _arr.length === i) break; } } catch (err) { _d = true; _e = err; } finally { try { if (!_n && _i[\"return\"] != null) _i[\"return\"](); } finally { if (_d) throw _e; } } return _arr; }\n\nfunction _arrayWithHoles(arr) { if (Array.isArray(arr)) return arr; }\n\n\n\n\n\n\n\nvar Code = function Code(_ref) {\n  var language = _ref.language,\n      fileName = _ref.fileName,\n      lines = _ref.lines;\n  var codeStyle = Object(react__WEBPACK_IMPORTED_MODULE_0__[\"useContext\"])(_AlgorithmVisualizer__WEBPACK_IMPORTED_MODULE_3__[\"CodeStyleContext\"]);\n\n  var _useContext = Object(react__WEBPACK_IMPORTED_MODULE_0__[\"useContext\"])(_AlgorithmVisualizer__WEBPACK_IMPORTED_MODULE_3__[\"CodeDataContext\"]),\n      _useContext2 = _slicedToArray(_useContext, 2),\n      codeData = _useContext2[0],\n      getCodeFile = _useContext2[1];\n\n  if (codeData[fileName] === undefined) {\n    getCodeFile(fileName);\n    return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(_Helpers__WEBPACK_IMPORTED_MODULE_2__[\"Loading\"], null);\n  }\n\n  var _lines = _slicedToArray(lines, 2),\n      start = _lines[0],\n      end = _lines[1];\n\n  var codeText = codeData[fileName].slice(start - 1, end).join(\"\\n\");\n  var style = Object(_Styles__WEBPACK_IMPORTED_MODULE_4__[\"getCodeStyle\"])(codeStyle.style);\n\n  var customStyle = _objectSpread({}, _Styles__WEBPACK_IMPORTED_MODULE_4__[\"baseCodeStyle\"], {\n    fontSize: codeStyle.fontSize\n  });\n\n  return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(react_syntax_highlighter__WEBPACK_IMPORTED_MODULE_1__[\"default\"], {\n    customStyle: customStyle,\n    language: language,\n    style: style\n  }, codeText);\n};\n\n/* harmony default export */ __webpack_exports__[\"default\"] = (Code);//# sourceURL=[module]\n//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJmaWxlIjoiLi9Db2RlL0FwcC9BbGdvcml0aG1WaXN1YWxpemVyL1Nob3dDb2RlLnRzeC5qcyIsInNvdXJjZXMiOlsid2VicGFjazovLy8uL0NvZGUvQXBwL0FsZ29yaXRobVZpc3VhbGl6ZXIvU2hvd0NvZGUudHN4PzdhMzYiXSwic291cmNlc0NvbnRlbnQiOlsiaW1wb3J0IFJlYWN0LCB7IEZ1bmN0aW9uQ29tcG9uZW50LCB1c2VDb250ZXh0IH0gZnJvbSBcInJlYWN0XCJcbmltcG9ydCBTeW50YXhIaWdobGlnaHRlciBmcm9tIFwicmVhY3Qtc3ludGF4LWhpZ2hsaWdodGVyXCJcblxuaW1wb3J0IHsgTG9hZGluZyB9IGZyb20gXCIuLi9IZWxwZXJzXCJcbmltcG9ydCB7IENvZGVEYXRhQ29udGV4dCwgQ29kZVN0eWxlQ29udGV4dCB9IGZyb20gXCIuLi9BbGdvcml0aG1WaXN1YWxpemVyXCJcblxuaW1wb3J0IHsgYmFzZUNvZGVTdHlsZSwgZ2V0Q29kZVN0eWxlIH0gZnJvbSBcIi4vU3R5bGVzXCJcblxuXG50eXBlIENvZGVUeXBlID0gRnVuY3Rpb25Db21wb25lbnQ8eyBsYW5ndWFnZTogc3RyaW5nOyBmaWxlTmFtZTogc3RyaW5nOyBsaW5lczogW251bWJlciwgbnVtYmVyXSB9PlxuY29uc3QgQ29kZTogQ29kZVR5cGUgPSAoeyBsYW5ndWFnZSwgZmlsZU5hbWUsIGxpbmVzIH0pID0+IHtcbiAgY29uc3QgY29kZVN0eWxlID0gdXNlQ29udGV4dChDb2RlU3R5bGVDb250ZXh0KVxuICBjb25zdCBbY29kZURhdGEsIGdldENvZGVGaWxlXSA9IHVzZUNvbnRleHQoQ29kZURhdGFDb250ZXh0KVxuXG4gIGlmIChjb2RlRGF0YVtmaWxlTmFtZV0gPT09IHVuZGVmaW5lZCkge1xuICAgIGdldENvZGVGaWxlKGZpbGVOYW1lKVxuICAgIHJldHVybiA8TG9hZGluZyAvPlxuICB9XG5cbiAgY29uc3QgW3N0YXJ0LCBlbmRdID0gbGluZXNcbiAgY29uc3QgY29kZVRleHQgPSBjb2RlRGF0YVtmaWxlTmFtZV0uc2xpY2Uoc3RhcnQgLSAxLCBlbmQpLmpvaW4oXCJcXG5cIilcbiAgY29uc3Qgc3R5bGUgPSBnZXRDb2RlU3R5bGUoY29kZVN0eWxlLnN0eWxlKVxuICBjb25zdCBjdXN0b21TdHlsZSA9IHsgLi4uYmFzZUNvZGVTdHlsZSwgZm9udFNpemU6IGNvZGVTdHlsZS5mb250U2l6ZSB9XG5cbiAgcmV0dXJuIDxTeW50YXhIaWdobGlnaHRlciB7Li4ueyBjdXN0b21TdHlsZSwgbGFuZ3VhZ2UsIHN0eWxlIH19Pntjb2RlVGV4dH08L1N5bnRheEhpZ2hsaWdodGVyPlxufVxuXG5leHBvcnQgZGVmYXVsdCBDb2RlXG4iXSwibWFwcGluZ3MiOiI7Ozs7Ozs7Ozs7Ozs7Ozs7Ozs7QUFBQTtBQUNBO0FBRUE7QUFDQTtBQUVBO0FBQ0E7QUFHQTtBQUFBO0FBQUE7QUFBQTtBQUNBO0FBQ0E7QUFGQTtBQUFBO0FBQUE7QUFBQTtBQUNBO0FBR0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQVJBO0FBQUE7QUFBQTtBQUNBO0FBU0E7QUFDQTtBQUNBO0FBQUE7QUFBQTtBQUFBO0FBQ0E7QUFDQTtBQUFBO0FBQUE7QUFBQTtBQUFBO0FBQ0E7QUFDQTtBQUNBIiwic291cmNlUm9vdCI6IiJ9\n//# sourceURL=webpack-internal:///./Code/App/AlgorithmVisualizer/ShowCode.tsx\n");

/***/ }),

/***/ "./Code/Data/NumberTheory/BinaryExponentation.tsx":
/*!********************************************************!*\
  !*** ./Code/Data/NumberTheory/BinaryExponentation.tsx ***!
  \********************************************************/
/*! exports provided: default */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
eval("__webpack_require__.r(__webpack_exports__);\n/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! react */ \"./node_modules/react/index.js\");\n/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_0__);\n/* harmony import */ var _material_ui_core__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @material-ui/core */ \"./node_modules/@material-ui/core/esm/index.js\");\n/* harmony import */ var react_katex__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! react-katex */ \"./node_modules/react-katex/dist/react-katex.js\");\n/* harmony import */ var react_katex__WEBPACK_IMPORTED_MODULE_2___default = /*#__PURE__*/__webpack_require__.n(react_katex__WEBPACK_IMPORTED_MODULE_2__);\n/* harmony import */ var _App_AlgorithmVisualizer_ShowCode__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ../../App/AlgorithmVisualizer/ShowCode */ \"./Code/App/AlgorithmVisualizer/ShowCode.tsx\");\nfunction _templateObject2() {\n  var data = _taggedTemplateLiteral([\"\\n            x^n = \\n            \\begin{cases}\\n            (x^2)^{space \\frac{n}{2}}           & \\text{if n is even}  \\\\\\n            x space (x^2)^{space \\frac{n-1}{2}}    & \\text{if n is odd}   \\\\\\n            end{cases}\\n        \"], [\"\\n            x^n = \\n            \\\\begin{cases}\\n            (x^2)^{\\\\space \\\\frac{n}{2}}           & \\\\text{if n is even}  \\\\\\\\\\n            x \\\\space (x^2)^{\\\\space \\\\frac{n-1}{2}}    & \\\\text{if n is odd}   \\\\\\\\\\n            \\\\end{cases}\\n        \"]);\n\n  _templateObject2 = function _templateObject2() {\n    return data;\n  };\n\n  return data;\n}\n\nfunction _templateObject() {\n  var data = _taggedTemplateLiteral([\"\\n            base ^ {exponent} = \\n            \\begin{cases}\\n            (base^2)^{space \\frac{exponent}{2}}             & \\text{if exponent is even}  \\\\\\n            base space (base^2)^{space \\frac{exponent-1}{2}}   & \\text{if exponent is odd}   \\\\\\n            end{cases}\\n        \"], [\"\\n            base ^ {exponent} = \\n            \\\\begin{cases}\\n            (base^2)^{\\\\space \\\\frac{exponent}{2}}             & \\\\text{if exponent is even}  \\\\\\\\\\n            base \\\\space (base^2)^{\\\\space \\\\frac{exponent-1}{2}}   & \\\\text{if exponent is odd}   \\\\\\\\\\n            \\\\end{cases}\\n        \"]);\n\n  _templateObject = function _templateObject() {\n    return data;\n  };\n\n  return data;\n}\n\nfunction _taggedTemplateLiteral(strings, raw) { if (!raw) { raw = strings.slice(0); } return Object.freeze(Object.defineProperties(strings, { raw: { value: Object.freeze(raw) } })); }\n\n\n\n\n\n\nvar Component = function Component() {\n  return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(\"div\", null, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(_material_ui_core__WEBPACK_IMPORTED_MODULE_1__[\"Typography\"], {\n    gutterBottom: true,\n    variant: \"h5\"\n  }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(_material_ui_core__WEBPACK_IMPORTED_MODULE_1__[\"Box\"], {\n    fontWeight: 800\n  }, \"Definition\")), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(\"p\", null, \"This function will performe \", react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(react_katex__WEBPACK_IMPORTED_MODULE_2__[\"InlineMath\"], {\n    math: \"base^{exponent}\"\n  }), \" but a little bit more fast using exponentiation by squaring. The idea is to see this way of expressing exponentiation:\"), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(react_katex__WEBPACK_IMPORTED_MODULE_2__[\"BlockMath\"], null, String.raw(_templateObject())), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(\"p\", null, \"Or if you like small variable names we can say that \", react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(react_katex__WEBPACK_IMPORTED_MODULE_2__[\"InlineMath\"], {\n    math: \"base = x\"\n  }), \" y\", \" \", react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(react_katex__WEBPACK_IMPORTED_MODULE_2__[\"InlineMath\"], {\n    math: \"exponent = n\"\n  }), \":\"), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(react_katex__WEBPACK_IMPORTED_MODULE_2__[\"BlockMath\"], null, String.raw(_templateObject2())), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(_App_AlgorithmVisualizer_ShowCode__WEBPACK_IMPORTED_MODULE_3__[\"default\"], {\n    language: \"cpp\",\n    fileName: \"BinaryExponentiation.cpp\",\n    lines: [1, 8]\n  }), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(_material_ui_core__WEBPACK_IMPORTED_MODULE_1__[\"Typography\"], {\n    gutterBottom: true,\n    variant: \"h5\"\n  }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(_material_ui_core__WEBPACK_IMPORTED_MODULE_1__[\"Box\"], {\n    fontWeight: 800\n  }, \"Simple Optimizations\")), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(\"p\", null, \"Now we want to eliminate the recursion and modify a little bit the idea:\"), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(\"ul\", null, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(\"li\", null, \"If exponent is odd, first do \", react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(react_katex__WEBPACK_IMPORTED_MODULE_2__[\"InlineMath\"], {\n    math: \"solution = base * solution\"\n  }), \", now, we have to delete 1 to the exponent, so the exponent is even, so we can just say that the base is \", react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(react_katex__WEBPACK_IMPORTED_MODULE_2__[\"InlineMath\"], {\n    math: \"base = base^2\"\n  }), \" and that the exponent is just the half of the original exponent.\"), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(\"li\", null, \"If exponent is even, so we can just say that the base is\", \" \", react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(react_katex__WEBPACK_IMPORTED_MODULE_2__[\"InlineMath\"], {\n    math: \"base = base^2\"\n  }), \" and that the exponent is just the half of the original exponent.\")), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(_App_AlgorithmVisualizer_ShowCode__WEBPACK_IMPORTED_MODULE_3__[\"default\"], {\n    language: \"cpp\",\n    fileName: \"BinaryExponentiation.cpp\",\n    lines: [10, 25]\n  }), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(_material_ui_core__WEBPACK_IMPORTED_MODULE_1__[\"Typography\"], {\n    gutterBottom: true,\n    variant: \"h5\"\n  }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(_material_ui_core__WEBPACK_IMPORTED_MODULE_1__[\"Box\"], {\n    fontWeight: 800\n  }, \"Optimizations\")), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(_material_ui_core__WEBPACK_IMPORTED_MODULE_1__[\"Typography\"], {\n    gutterBottom: true,\n    variant: \"subtitle1\"\n  }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(_material_ui_core__WEBPACK_IMPORTED_MODULE_1__[\"Box\"], {\n    fontWeight: 600\n  }, \"How to optimize \", react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(react_katex__WEBPACK_IMPORTED_MODULE_2__[\"InlineMath\"], {\n    math: \"e = \\\\frac{e-1}{2}\"\n  }), \" and\", \" \", react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(react_katex__WEBPACK_IMPORTED_MODULE_2__[\"InlineMath\"], {\n    math: \"e = \\\\frac{e}{2}\"\n  }))), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(\"p\", null, \"Remember the bitwise operations equalities:\"), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(\"ul\", null, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(\"li\", null, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(react_katex__WEBPACK_IMPORTED_MODULE_2__[\"InlineMath\"], {\n    math: \"x << y = x * 2^y\"\n  })), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(\"li\", null, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(react_katex__WEBPACK_IMPORTED_MODULE_2__[\"InlineMath\"], {\n    math: \"x >> y = \\\\left \\\\lfloor \\\\dfrac{x}{2^y} \\\\right \\\\rfloor\"\n  }))), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(\"p\", null, \"This optimizations are using the bitwise operations. I claim that\", \" \", react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(react_katex__WEBPACK_IMPORTED_MODULE_2__[\"InlineMath\"], {\n    math: \"e = \\\\frac{e-1}{2}\"\n  }), \" and \", react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(react_katex__WEBPACK_IMPORTED_MODULE_2__[\"InlineMath\"], {\n    math: \"e = \\\\frac{e}{2}\"\n  }), \" are equal to \", react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(react_katex__WEBPACK_IMPORTED_MODULE_2__[\"InlineMath\"], {\n    math: \"e = e >> 1\"\n  })), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(\"p\", null, \"This is easy to proof, because \", react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(react_katex__WEBPACK_IMPORTED_MODULE_2__[\"InlineMath\"], {\n    math: \"e = e >> 1\"\n  }), \" delete the least significant bit, so the last bit does not really matter. So you find that at the end it does not matter if it is odd or even this will always give you the correct answer.\"), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(_material_ui_core__WEBPACK_IMPORTED_MODULE_1__[\"Typography\"], {\n    gutterBottom: true,\n    variant: \"subtitle1\"\n  }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(_material_ui_core__WEBPACK_IMPORTED_MODULE_1__[\"Box\"], {\n    fontWeight: 600\n  }, \"Check in the exponent is odd or even\")), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(\"p\", null, \"To do this just do exponent & 1.\"), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(\"p\", null, \"For example the number \", react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(react_katex__WEBPACK_IMPORTED_MODULE_2__[\"InlineMath\"], {\n    math: \"000101101010\"\n  }), \" if the exponent was odd then the last digit will be 1, so exponent & 1 give true only if the last digit was 1.\"), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(_App_AlgorithmVisualizer_ShowCode__WEBPACK_IMPORTED_MODULE_3__[\"default\"], {\n    language: \"cpp\",\n    fileName: \"BinaryExponentiation.cpp\",\n    lines: [27, 39]\n  }), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(_material_ui_core__WEBPACK_IMPORTED_MODULE_1__[\"Typography\"], {\n    gutterBottom: true,\n    variant: \"h5\"\n  }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(_material_ui_core__WEBPACK_IMPORTED_MODULE_1__[\"Box\"], {\n    fontWeight: 800\n  }, \"Modular Exponentation\")), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(\"p\", null, \"This is to do \", react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(react_katex__WEBPACK_IMPORTED_MODULE_2__[\"InlineMath\"], {\n    math: \"base^{exponent}  \\\\space \\\\space \\\\mod \\\\space n\"\n  })), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(_App_AlgorithmVisualizer_ShowCode__WEBPACK_IMPORTED_MODULE_3__[\"default\"], {\n    language: \"cpp\",\n    fileName: \"BinaryExponentiation.cpp\",\n    lines: [41, 54]\n  }));\n};\n\n/* harmony default export */ __webpack_exports__[\"default\"] = (Component);//# sourceURL=[module]\n//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJmaWxlIjoiLi9Db2RlL0RhdGEvTnVtYmVyVGhlb3J5L0JpbmFyeUV4cG9uZW50YXRpb24udHN4LmpzIiwic291cmNlcyI6WyJ3ZWJwYWNrOi8vLy4vQ29kZS9EYXRhL051bWJlclRoZW9yeS9CaW5hcnlFeHBvbmVudGF0aW9uLnRzeD8zMzA2Il0sInNvdXJjZXNDb250ZW50IjpbImltcG9ydCBSZWFjdCwgeyBGdW5jdGlvbkNvbXBvbmVudCB9IGZyb20gXCJyZWFjdFwiXG5cbmltcG9ydCB7IFR5cG9ncmFwaHksIEJveCB9IGZyb20gXCJAbWF0ZXJpYWwtdWkvY29yZVwiXG5pbXBvcnQgeyBJbmxpbmVNYXRoLCBCbG9ja01hdGggfSBmcm9tIFwicmVhY3Qta2F0ZXhcIlxuXG5pbXBvcnQgQ29kZSBmcm9tIFwiLi4vLi4vQXBwL0FsZ29yaXRobVZpc3VhbGl6ZXIvU2hvd0NvZGVcIlxuXG5jb25zdCBDb21wb25lbnQ6IEZ1bmN0aW9uQ29tcG9uZW50ID0gKCkgPT4ge1xuICByZXR1cm4gKFxuICAgIDxkaXY+XG4gICAgICA8VHlwb2dyYXBoeSBndXR0ZXJCb3R0b20gdmFyaWFudD1cImg1XCI+XG4gICAgICAgIDxCb3ggZm9udFdlaWdodD17ODAwfT5EZWZpbml0aW9uPC9Cb3g+XG4gICAgICA8L1R5cG9ncmFwaHk+XG5cbiAgICAgIDxwPlxuICAgICAgICBUaGlzIGZ1bmN0aW9uIHdpbGwgcGVyZm9ybWUgPElubGluZU1hdGggbWF0aD1cImJhc2Vee2V4cG9uZW50fVwiIC8+IGJ1dCBhIGxpdHRsZSBiaXQgbW9yZSBmYXN0XG4gICAgICAgIHVzaW5nIGV4cG9uZW50aWF0aW9uIGJ5IHNxdWFyaW5nLiBUaGUgaWRlYSBpcyB0byBzZWUgdGhpcyB3YXkgb2YgZXhwcmVzc2luZyBleHBvbmVudGlhdGlvbjpcbiAgICAgIDwvcD5cbiAgICAgIDxCbG9ja01hdGg+XG4gICAgICAgIHtTdHJpbmcucmF3YFxuICAgICAgICAgICAgYmFzZSBeIHtleHBvbmVudH0gPSBcbiAgICAgICAgICAgIFxcYmVnaW57Y2FzZXN9XG4gICAgICAgICAgICAoYmFzZV4yKV57XFxzcGFjZSBcXGZyYWN7ZXhwb25lbnR9ezJ9fSAgICAgICAgICAgICAmIFxcdGV4dHtpZiBleHBvbmVudCBpcyBldmVufSAgXFxcXFxuICAgICAgICAgICAgYmFzZSBcXHNwYWNlIChiYXNlXjIpXntcXHNwYWNlIFxcZnJhY3tleHBvbmVudC0xfXsyfX0gICAmIFxcdGV4dHtpZiBleHBvbmVudCBpcyBvZGR9ICAgXFxcXFxuICAgICAgICAgICAgXFxlbmR7Y2FzZXN9XG4gICAgICAgIGB9XG4gICAgICA8L0Jsb2NrTWF0aD5cbiAgICAgIDxwPlxuICAgICAgICBPciBpZiB5b3UgbGlrZSBzbWFsbCB2YXJpYWJsZSBuYW1lcyB3ZSBjYW4gc2F5IHRoYXQgPElubGluZU1hdGggbWF0aD1cImJhc2UgPSB4XCIgLz4geXtcIiBcIn1cbiAgICAgICAgPElubGluZU1hdGggbWF0aD1cImV4cG9uZW50ID0gblwiIC8+OlxuICAgICAgPC9wPlxuICAgICAgPEJsb2NrTWF0aD5cbiAgICAgICAge1N0cmluZy5yYXdgXG4gICAgICAgICAgICB4Xm4gPSBcbiAgICAgICAgICAgIFxcYmVnaW57Y2FzZXN9XG4gICAgICAgICAgICAoeF4yKV57XFxzcGFjZSBcXGZyYWN7bn17Mn19ICAgICAgICAgICAmIFxcdGV4dHtpZiBuIGlzIGV2ZW59ICBcXFxcXG4gICAgICAgICAgICB4IFxcc3BhY2UgKHheMilee1xcc3BhY2UgXFxmcmFje24tMX17Mn19ICAgICYgXFx0ZXh0e2lmIG4gaXMgb2RkfSAgIFxcXFxcbiAgICAgICAgICAgIFxcZW5ke2Nhc2VzfVxuICAgICAgICBgfVxuICAgICAgPC9CbG9ja01hdGg+XG5cbiAgICAgIDxDb2RlIGxhbmd1YWdlPXtcImNwcFwifSBmaWxlTmFtZT17XCJCaW5hcnlFeHBvbmVudGlhdGlvbi5jcHBcIn0gbGluZXM9e1sxLCA4XX0gLz5cblxuICAgICAgPFR5cG9ncmFwaHkgZ3V0dGVyQm90dG9tIHZhcmlhbnQ9XCJoNVwiPlxuICAgICAgICA8Qm94IGZvbnRXZWlnaHQ9ezgwMH0+U2ltcGxlIE9wdGltaXphdGlvbnM8L0JveD5cbiAgICAgIDwvVHlwb2dyYXBoeT5cblxuICAgICAgPHA+Tm93IHdlIHdhbnQgdG8gZWxpbWluYXRlIHRoZSByZWN1cnNpb24gYW5kIG1vZGlmeSBhIGxpdHRsZSBiaXQgdGhlIGlkZWE6PC9wPlxuICAgICAgPHVsPlxuICAgICAgICA8bGk+XG4gICAgICAgICAgSWYgZXhwb25lbnQgaXMgb2RkLCBmaXJzdCBkbyA8SW5saW5lTWF0aCBtYXRoPVwic29sdXRpb24gPSBiYXNlICogc29sdXRpb25cIiAvPiwgbm93LCB3ZVxuICAgICAgICAgIGhhdmUgdG8gZGVsZXRlIDEgdG8gdGhlIGV4cG9uZW50LCBzbyB0aGUgZXhwb25lbnQgaXMgZXZlbiwgc28gd2UgY2FuIGp1c3Qgc2F5IHRoYXQgdGhlXG4gICAgICAgICAgYmFzZSBpcyA8SW5saW5lTWF0aCBtYXRoPVwiYmFzZSA9IGJhc2VeMlwiIC8+IGFuZCB0aGF0IHRoZSBleHBvbmVudCBpcyBqdXN0IHRoZSBoYWxmIG9mIHRoZVxuICAgICAgICAgIG9yaWdpbmFsIGV4cG9uZW50LlxuICAgICAgICA8L2xpPlxuICAgICAgICA8bGk+XG4gICAgICAgICAgSWYgZXhwb25lbnQgaXMgZXZlbiwgc28gd2UgY2FuIGp1c3Qgc2F5IHRoYXQgdGhlIGJhc2UgaXN7XCIgXCJ9XG4gICAgICAgICAgPElubGluZU1hdGggbWF0aD1cImJhc2UgPSBiYXNlXjJcIiAvPiBhbmQgdGhhdCB0aGUgZXhwb25lbnQgaXMganVzdCB0aGUgaGFsZiBvZiB0aGUgb3JpZ2luYWxcbiAgICAgICAgICBleHBvbmVudC5cbiAgICAgICAgPC9saT5cbiAgICAgIDwvdWw+XG5cbiAgICAgIDxDb2RlIGxhbmd1YWdlPXtcImNwcFwifSBmaWxlTmFtZT17XCJCaW5hcnlFeHBvbmVudGlhdGlvbi5jcHBcIn0gbGluZXM9e1sxMCwgMjVdfSAvPlxuXG4gICAgICA8VHlwb2dyYXBoeSBndXR0ZXJCb3R0b20gdmFyaWFudD1cImg1XCI+XG4gICAgICAgIDxCb3ggZm9udFdlaWdodD17ODAwfT5PcHRpbWl6YXRpb25zPC9Cb3g+XG4gICAgICA8L1R5cG9ncmFwaHk+XG5cbiAgICAgIDxUeXBvZ3JhcGh5IGd1dHRlckJvdHRvbSB2YXJpYW50PVwic3VidGl0bGUxXCI+XG4gICAgICAgIDxCb3ggZm9udFdlaWdodD17NjAwfT5cbiAgICAgICAgICBIb3cgdG8gb3B0aW1pemUgPElubGluZU1hdGggbWF0aD1cImUgPSBcXGZyYWN7ZS0xfXsyfVwiIC8+IGFuZHtcIiBcIn1cbiAgICAgICAgICA8SW5saW5lTWF0aCBtYXRoPVwiZSA9IFxcZnJhY3tlfXsyfVwiIC8+XG4gICAgICAgIDwvQm94PlxuICAgICAgPC9UeXBvZ3JhcGh5PlxuXG4gICAgICA8cD5SZW1lbWJlciB0aGUgYml0d2lzZSBvcGVyYXRpb25zIGVxdWFsaXRpZXM6PC9wPlxuICAgICAgPHVsPlxuICAgICAgICA8bGk+XG4gICAgICAgICAgPElubGluZU1hdGggbWF0aD1cInggPDwgeSA9IHggKiAyXnlcIiAvPlxuICAgICAgICA8L2xpPlxuICAgICAgICA8bGk+XG4gICAgICAgICAgPElubGluZU1hdGggbWF0aD1cInggPj4geSA9IFxcbGVmdCBcXGxmbG9vciBcXGRmcmFje3h9ezJeeX0gXFxyaWdodCBcXHJmbG9vclwiIC8+XG4gICAgICAgIDwvbGk+XG4gICAgICA8L3VsPlxuICAgICAgPHA+XG4gICAgICAgIFRoaXMgb3B0aW1pemF0aW9ucyBhcmUgdXNpbmcgdGhlIGJpdHdpc2Ugb3BlcmF0aW9ucy4gSSBjbGFpbSB0aGF0e1wiIFwifVxuICAgICAgICA8SW5saW5lTWF0aCBtYXRoPVwiZSA9IFxcZnJhY3tlLTF9ezJ9XCIgLz4gYW5kIDxJbmxpbmVNYXRoIG1hdGg9XCJlID0gXFxmcmFje2V9ezJ9XCIgLz4gYXJlIGVxdWFsXG4gICAgICAgIHRvIDxJbmxpbmVNYXRoIG1hdGg9XCJlID0gZSA+PiAxXCIgLz5cbiAgICAgIDwvcD5cbiAgICAgIDxwPlxuICAgICAgICBUaGlzIGlzIGVhc3kgdG8gcHJvb2YsIGJlY2F1c2UgPElubGluZU1hdGggbWF0aD1cImUgPSBlID4+IDFcIiAvPiBkZWxldGUgdGhlIGxlYXN0IHNpZ25pZmljYW50XG4gICAgICAgIGJpdCwgc28gdGhlIGxhc3QgYml0IGRvZXMgbm90IHJlYWxseSBtYXR0ZXIuIFNvIHlvdSBmaW5kIHRoYXQgYXQgdGhlIGVuZCBpdCBkb2VzIG5vdCBtYXR0ZXJcbiAgICAgICAgaWYgaXQgaXMgb2RkIG9yIGV2ZW4gdGhpcyB3aWxsIGFsd2F5cyBnaXZlIHlvdSB0aGUgY29ycmVjdCBhbnN3ZXIuXG4gICAgICA8L3A+XG5cbiAgICAgIDxUeXBvZ3JhcGh5IGd1dHRlckJvdHRvbSB2YXJpYW50PVwic3VidGl0bGUxXCI+XG4gICAgICAgIDxCb3ggZm9udFdlaWdodD17NjAwfT5DaGVjayBpbiB0aGUgZXhwb25lbnQgaXMgb2RkIG9yIGV2ZW48L0JveD5cbiAgICAgIDwvVHlwb2dyYXBoeT5cblxuICAgICAgPHA+VG8gZG8gdGhpcyBqdXN0IGRvIGV4cG9uZW50ICYgMS48L3A+XG4gICAgICA8cD5cbiAgICAgICAgRm9yIGV4YW1wbGUgdGhlIG51bWJlciA8SW5saW5lTWF0aCBtYXRoPVwiMDAwMTAxMTAxMDEwXCIgLz4gaWYgdGhlIGV4cG9uZW50IHdhcyBvZGQgdGhlbiB0aGVcbiAgICAgICAgbGFzdCBkaWdpdCB3aWxsIGJlIDEsIHNvIGV4cG9uZW50ICYgMSBnaXZlIHRydWUgb25seSBpZiB0aGUgbGFzdCBkaWdpdCB3YXMgMS5cbiAgICAgIDwvcD5cblxuICAgICAgPENvZGUgbGFuZ3VhZ2U9e1wiY3BwXCJ9IGZpbGVOYW1lPXtcIkJpbmFyeUV4cG9uZW50aWF0aW9uLmNwcFwifSBsaW5lcz17WzI3LCAzOV19IC8+XG5cbiAgICAgIDxUeXBvZ3JhcGh5IGd1dHRlckJvdHRvbSB2YXJpYW50PVwiaDVcIj5cbiAgICAgICAgPEJveCBmb250V2VpZ2h0PXs4MDB9Pk1vZHVsYXIgRXhwb25lbnRhdGlvbjwvQm94PlxuICAgICAgPC9UeXBvZ3JhcGh5PlxuXG4gICAgICA8cD5cbiAgICAgICAgVGhpcyBpcyB0byBkbyA8SW5saW5lTWF0aCBtYXRoPVwiYmFzZV57ZXhwb25lbnR9ICBcXHNwYWNlIFxcc3BhY2UgXFxtb2QgXFxzcGFjZSBuXCIgLz5cbiAgICAgIDwvcD5cblxuICAgICAgPENvZGUgbGFuZ3VhZ2U9e1wiY3BwXCJ9IGZpbGVOYW1lPXtcIkJpbmFyeUV4cG9uZW50aWF0aW9uLmNwcFwifSBsaW5lcz17WzQxLCA1NF19IC8+XG4gICAgPC9kaXY+XG4gIClcbn1cblxuZXhwb3J0IGRlZmF1bHQgQ29tcG9uZW50XG4iXSwibWFwcGluZ3MiOiI7Ozs7Ozs7Ozs7Ozs7Ozs7Ozs7Ozs7Ozs7Ozs7O0FBQUE7QUFFQTtBQUNBO0FBRUE7QUFDQTtBQUNBO0FBQ0E7QUFFQTtBQUFBO0FBQUE7QUFDQTtBQUFBO0FBSUE7QUFBQTtBQWFBO0FBQUE7QUFDQTtBQUFBO0FBWUE7QUFBQTtBQUFBO0FBQUE7QUFFQTtBQUFBO0FBQUE7QUFDQTtBQUFBO0FBTUE7QUFBQTtBQUVBO0FBQUE7QUFLQTtBQUFBO0FBS0E7QUFBQTtBQUFBO0FBQUE7QUFFQTtBQUFBO0FBQUE7QUFDQTtBQUFBO0FBR0E7QUFBQTtBQUFBO0FBQ0E7QUFBQTtBQUNBO0FBQUE7QUFDQTtBQUFBO0FBT0E7QUFBQTtBQUdBO0FBQUE7QUFLQTtBQUFBO0FBQUE7QUFBQTtBQUNBO0FBQUE7QUFHQTtBQUFBO0FBS0E7QUFBQTtBQUFBO0FBQ0E7QUFBQTtBQUtBO0FBQUE7QUFJQTtBQUFBO0FBQUE7QUFBQTtBQUVBO0FBQUE7QUFBQTtBQUNBO0FBQUE7QUFJQTtBQUFBO0FBR0E7QUFBQTtBQUFBO0FBQUE7QUFHQTtBQUNBO0FBQ0EiLCJzb3VyY2VSb290IjoiIn0=\n//# sourceURL=webpack-internal:///./Code/Data/NumberTheory/BinaryExponentation.tsx\n");

/***/ })

}]);