(window["webpackJsonp"] = window["webpackJsonp"] || []).push([["react-syntax-highlighter_languages_highlight_elm"],{

/***/ "./node_modules/react-syntax-highlighter/node_modules/highlight.js/lib/languages/elm.js":
/*!**********************************************************************************************!*\
  !*** ./node_modules/react-syntax-highlighter/node_modules/highlight.js/lib/languages/elm.js ***!
  \**********************************************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

eval("module.exports = function(hljs) {\n  var COMMENT = {\n    variants: [\n      hljs.COMMENT('--', '$'),\n      hljs.COMMENT(\n        '{-',\n        '-}',\n        {\n          contains: ['self']\n        }\n      )\n    ]\n  };\n\n  var CONSTRUCTOR = {\n    className: 'type',\n    begin: '\\\\b[A-Z][\\\\w\\']*', // TODO: other constructors (built-in, infix).\n    relevance: 0\n  };\n\n  var LIST = {\n    begin: '\\\\(', end: '\\\\)',\n    illegal: '\"',\n    contains: [\n      {className: 'type', begin: '\\\\b[A-Z][\\\\w]*(\\\\((\\\\.\\\\.|,|\\\\w+)\\\\))?'},\n      COMMENT\n    ]\n  };\n\n  var RECORD = {\n    begin: '{', end: '}',\n    contains: LIST.contains\n  };\n\n  var CHARACTER = {\n    className: 'string',\n    begin: '\\'\\\\\\\\?.', end: '\\'',\n    illegal: '.'\n  };\n\n  return {\n    keywords:\n      'let in if then else case of where module import exposing ' +\n      'type alias as infix infixl infixr port effect command subscription',\n    contains: [\n\n      // Top-level constructions.\n\n      {\n        beginKeywords: 'port effect module', end: 'exposing',\n        keywords: 'port effect module where command subscription exposing',\n        contains: [LIST, COMMENT],\n        illegal: '\\\\W\\\\.|;'\n      },\n      {\n        begin: 'import', end: '$',\n        keywords: 'import as exposing',\n        contains: [LIST, COMMENT],\n        illegal: '\\\\W\\\\.|;'\n      },\n      {\n        begin: 'type', end: '$',\n        keywords: 'type alias',\n        contains: [CONSTRUCTOR, LIST, RECORD, COMMENT]\n      },\n      {\n        beginKeywords: 'infix infixl infixr', end: '$',\n        contains: [hljs.C_NUMBER_MODE, COMMENT]\n      },\n      {\n        begin: 'port', end: '$',\n        keywords: 'port',\n        contains: [COMMENT]\n      },\n\n      // Literals and names.\n\n      CHARACTER,\n      hljs.QUOTE_STRING_MODE,\n      hljs.C_NUMBER_MODE,\n      CONSTRUCTOR,\n      hljs.inherit(hljs.TITLE_MODE, {begin: '^[_a-z][\\\\w\\']*'}),\n      COMMENT,\n\n      {begin: '->|<-'} // No markup, relevance booster\n    ],\n    illegal: /;/\n  };\n};//# sourceURL=[module]\n//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJmaWxlIjoiLi9ub2RlX21vZHVsZXMvcmVhY3Qtc3ludGF4LWhpZ2hsaWdodGVyL25vZGVfbW9kdWxlcy9oaWdobGlnaHQuanMvbGliL2xhbmd1YWdlcy9lbG0uanMuanMiLCJzb3VyY2VzIjpbIndlYnBhY2s6Ly8vLi9ub2RlX21vZHVsZXMvcmVhY3Qtc3ludGF4LWhpZ2hsaWdodGVyL25vZGVfbW9kdWxlcy9oaWdobGlnaHQuanMvbGliL2xhbmd1YWdlcy9lbG0uanM/Y2ViNCJdLCJzb3VyY2VzQ29udGVudCI6WyJtb2R1bGUuZXhwb3J0cyA9IGZ1bmN0aW9uKGhsanMpIHtcbiAgdmFyIENPTU1FTlQgPSB7XG4gICAgdmFyaWFudHM6IFtcbiAgICAgIGhsanMuQ09NTUVOVCgnLS0nLCAnJCcpLFxuICAgICAgaGxqcy5DT01NRU5UKFxuICAgICAgICAney0nLFxuICAgICAgICAnLX0nLFxuICAgICAgICB7XG4gICAgICAgICAgY29udGFpbnM6IFsnc2VsZiddXG4gICAgICAgIH1cbiAgICAgIClcbiAgICBdXG4gIH07XG5cbiAgdmFyIENPTlNUUlVDVE9SID0ge1xuICAgIGNsYXNzTmFtZTogJ3R5cGUnLFxuICAgIGJlZ2luOiAnXFxcXGJbQS1aXVtcXFxcd1xcJ10qJywgLy8gVE9ETzogb3RoZXIgY29uc3RydWN0b3JzIChidWlsdC1pbiwgaW5maXgpLlxuICAgIHJlbGV2YW5jZTogMFxuICB9O1xuXG4gIHZhciBMSVNUID0ge1xuICAgIGJlZ2luOiAnXFxcXCgnLCBlbmQ6ICdcXFxcKScsXG4gICAgaWxsZWdhbDogJ1wiJyxcbiAgICBjb250YWluczogW1xuICAgICAge2NsYXNzTmFtZTogJ3R5cGUnLCBiZWdpbjogJ1xcXFxiW0EtWl1bXFxcXHddKihcXFxcKChcXFxcLlxcXFwufCx8XFxcXHcrKVxcXFwpKT8nfSxcbiAgICAgIENPTU1FTlRcbiAgICBdXG4gIH07XG5cbiAgdmFyIFJFQ09SRCA9IHtcbiAgICBiZWdpbjogJ3snLCBlbmQ6ICd9JyxcbiAgICBjb250YWluczogTElTVC5jb250YWluc1xuICB9O1xuXG4gIHZhciBDSEFSQUNURVIgPSB7XG4gICAgY2xhc3NOYW1lOiAnc3RyaW5nJyxcbiAgICBiZWdpbjogJ1xcJ1xcXFxcXFxcPy4nLCBlbmQ6ICdcXCcnLFxuICAgIGlsbGVnYWw6ICcuJ1xuICB9O1xuXG4gIHJldHVybiB7XG4gICAga2V5d29yZHM6XG4gICAgICAnbGV0IGluIGlmIHRoZW4gZWxzZSBjYXNlIG9mIHdoZXJlIG1vZHVsZSBpbXBvcnQgZXhwb3NpbmcgJyArXG4gICAgICAndHlwZSBhbGlhcyBhcyBpbmZpeCBpbmZpeGwgaW5maXhyIHBvcnQgZWZmZWN0IGNvbW1hbmQgc3Vic2NyaXB0aW9uJyxcbiAgICBjb250YWluczogW1xuXG4gICAgICAvLyBUb3AtbGV2ZWwgY29uc3RydWN0aW9ucy5cblxuICAgICAge1xuICAgICAgICBiZWdpbktleXdvcmRzOiAncG9ydCBlZmZlY3QgbW9kdWxlJywgZW5kOiAnZXhwb3NpbmcnLFxuICAgICAgICBrZXl3b3JkczogJ3BvcnQgZWZmZWN0IG1vZHVsZSB3aGVyZSBjb21tYW5kIHN1YnNjcmlwdGlvbiBleHBvc2luZycsXG4gICAgICAgIGNvbnRhaW5zOiBbTElTVCwgQ09NTUVOVF0sXG4gICAgICAgIGlsbGVnYWw6ICdcXFxcV1xcXFwufDsnXG4gICAgICB9LFxuICAgICAge1xuICAgICAgICBiZWdpbjogJ2ltcG9ydCcsIGVuZDogJyQnLFxuICAgICAgICBrZXl3b3JkczogJ2ltcG9ydCBhcyBleHBvc2luZycsXG4gICAgICAgIGNvbnRhaW5zOiBbTElTVCwgQ09NTUVOVF0sXG4gICAgICAgIGlsbGVnYWw6ICdcXFxcV1xcXFwufDsnXG4gICAgICB9LFxuICAgICAge1xuICAgICAgICBiZWdpbjogJ3R5cGUnLCBlbmQ6ICckJyxcbiAgICAgICAga2V5d29yZHM6ICd0eXBlIGFsaWFzJyxcbiAgICAgICAgY29udGFpbnM6IFtDT05TVFJVQ1RPUiwgTElTVCwgUkVDT1JELCBDT01NRU5UXVxuICAgICAgfSxcbiAgICAgIHtcbiAgICAgICAgYmVnaW5LZXl3b3JkczogJ2luZml4IGluZml4bCBpbmZpeHInLCBlbmQ6ICckJyxcbiAgICAgICAgY29udGFpbnM6IFtobGpzLkNfTlVNQkVSX01PREUsIENPTU1FTlRdXG4gICAgICB9LFxuICAgICAge1xuICAgICAgICBiZWdpbjogJ3BvcnQnLCBlbmQ6ICckJyxcbiAgICAgICAga2V5d29yZHM6ICdwb3J0JyxcbiAgICAgICAgY29udGFpbnM6IFtDT01NRU5UXVxuICAgICAgfSxcblxuICAgICAgLy8gTGl0ZXJhbHMgYW5kIG5hbWVzLlxuXG4gICAgICBDSEFSQUNURVIsXG4gICAgICBobGpzLlFVT1RFX1NUUklOR19NT0RFLFxuICAgICAgaGxqcy5DX05VTUJFUl9NT0RFLFxuICAgICAgQ09OU1RSVUNUT1IsXG4gICAgICBobGpzLmluaGVyaXQoaGxqcy5USVRMRV9NT0RFLCB7YmVnaW46ICdeW19hLXpdW1xcXFx3XFwnXSonfSksXG4gICAgICBDT01NRU5ULFxuXG4gICAgICB7YmVnaW46ICctPnw8LSd9IC8vIE5vIG1hcmt1cCwgcmVsZXZhbmNlIGJvb3N0ZXJcbiAgICBdLFxuICAgIGlsbGVnYWw6IC87L1xuICB9O1xufTsiXSwibWFwcGluZ3MiOiJBQUFBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0EiLCJzb3VyY2VSb290IjoiIn0=\n//# sourceURL=webpack-internal:///./node_modules/react-syntax-highlighter/node_modules/highlight.js/lib/languages/elm.js\n");

/***/ })

}]);